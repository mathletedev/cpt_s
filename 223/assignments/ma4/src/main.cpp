#include <algorithm>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>

// Size of the collection
constexpr int N = 10000;
// Max limit for the random generation
constexpr int MAX_VAL = 100000;
// Total trial (use the same for other sorting algorithms)
constexpr int TRIALS = 10;

void insertionSort(std::vector<int> &arr) {
	// 0..i is the sorted section of `arr`
	for (size_t i = 1; i < arr.size(); ++i) {
		// temp key to swap at the end
		int key = arr[i];
		size_t j = i;
		// move current element to left until it's in the right place
		while (j > 0 && arr[j - 1] > key) {
			arr[j] = arr[j - 1];
			--j;
		}
		arr[j] = key;
	}
}

void quickSortRec(std::vector<int> &arr, ssize_t left, ssize_t right) {
	if (left >= right) {
		return;
	}

	int pivot = arr[right];

	// `ssize_t` allows for negative values
	ssize_t i = left - 1, j = left;
	while (j < right) {
		if (arr[j] < pivot) {
			// swap larger elements to the left
			// i only advances for smaller elements
			std::swap(arr[++i], arr[j]);
		}
		++j;
	}
	std::swap(arr[i + 1], arr[right]);

	quickSortRec(arr, left, i);
	quickSortRec(arr, i + 2, right);
}

void quickSort(std::vector<int> &arr) {
	quickSortRec(arr, 0, arr.size() - 1);
}

// sequences labelled by OEIS index
namespace gapSequence {
	std::vector<size_t> A000225(int N) {
		std::vector<size_t> res;

		// # bits in `int` - # leading zeros in N - 1 = fast log_2(N)
		int log2N = sizeof(int) * CHAR_BIT - __builtin_clz(N) - 1;
		for (int k = log2N; k >= 1; --k) {
			// 2^i - 1
			res.push_back((1 << k) - 1);
		}

		return res;
	}
	std::vector<size_t> A003462(int N) {
		std::vector<size_t> res;

		int k = 0;
		while (true) {
			// (3^k - 1) / 2 > ceil(N / 3)
			int x = (std::pow(3, k) - 1) / 2;
			if (x > std::ceil(N / 3.0)) {
				break;
			}

			res.push_back(x);
			++k;
		}

		std::reverse(res.begin(), res.end());
		return res;
	}
	std::vector<size_t> A108870(int N) {
		std::vector<size_t> res;

		int k = 0;
		while (true) {
			// ceil(1/5 * (9 * (9/4)^(k - 1) - 4))
			int x = std::ceil(0.2 *
					  (9 * std::pow(9.0 / 4.0, k - 1) - 4));
			if (x >= N) {
				break;
			}

			res.push_back(x);
			++k;
		}

		std::reverse(res.begin(), res.end());
		return res;
	}
} // namespace gapSequence

void shellSort(std::vector<int> &arr, std::vector<size_t> &gaps) {
	for (size_t gap : gaps) {
		// exact same code as insertion sort, but now with gaps
		for (size_t i = gap; i < arr.size(); ++i) {
			int key = arr[i];
			size_t j = i;
			while (j >= gap && arr[j - gap] > key) {
				arr[j] = arr[j - gap];
				j -= gap;
			}
			arr[j] = key;
		}
	}
}

void percolateDown(std::vector<int> &heap, size_t size, size_t i) {
	size_t left = 2 * i + 1;
	size_t right = 2 * i + 2;

	size_t largest = i;
	// using > for a max heap (inverse of sorted order)
	if (left < size && heap[left] > heap[largest]) {
		largest = left;
	}
	if (right < size && heap[right] > heap[largest]) {
		largest = right;
	}

	if (largest == i) {
		return;
	}

	// keep going down
	std::swap(heap[i], heap[largest]);
	percolateDown(heap, size, largest);
}

void heapSort(std::vector<int> &arr) {
	// no need to percolate down on leaf nodes
	// (start from second-to-last level)
	for (ssize_t i = arr.size() / 2 - 1; i >= 0; --i) {
		percolateDown(arr, arr.size(), i);
	}

	for (ssize_t i = arr.size() - 1; i > 0; --i) {
		// swap largest element to the front of sorted section
		std::swap(arr[0], arr[i]);
		// percolate down new root
		percolateDown(arr, i, 0);
	}
}

void printStatistics(const std::vector<double> &durations) {
	double minTime = *min_element(durations.begin(), durations.end());
	double maxTime = *max_element(durations.begin(), durations.end());
	double avgTime = accumulate(durations.begin(), durations.end(), 0.0) /
			 durations.size();

	double variance = 0.0;
	for (double t : durations) {
		variance += (t - avgTime) * (t - avgTime);
	}
	double stdDev = sqrt(variance / durations.size());

	std::cout << "\n=== Statistics ===\n";
	std::cout << "Min Time: " << minTime << " ms\n";
	std::cout << "Max Time: " << maxTime << " ms\n";
	std::cout << "Average Time: " << avgTime << " ms\n";
	std::cout << "Standard Deviation: " << stdDev << " ms\n";
	std::cout << std::endl;
}

void benchmark(std::function<void(std::vector<int> &arr)> f, std::string name) {
	std::cout << "=== " << name << " ===" << std::endl;

	std::vector<double> durations;

	for (int trial = 0; trial < TRIALS; ++trial) {
		// make a copy of the `data` to assert against
		std::vector<int> data(N), verified(N);
		// Generate 10,000 random numbers and populate data
		for (int i = 0; i < N; ++i) {
			verified[i] = data[i] = rand() % (MAX_VAL + 1);
		}

		auto start = std::chrono::high_resolution_clock::now();
		f(data); // sort data
		auto end = std::chrono::high_resolution_clock::now();

		// assert that function is correct using `std::sort`
		std::sort(verified.begin(), verified.end());
		assert(data == verified);

		std::chrono::duration<double, std::milli> elapsed = end - start;
		durations.push_back(elapsed.count());

		std::cout << "Trial " << trial + 1
			  << " duration: " << elapsed.count() << " ms\n";
	}

	printStatistics(durations);
}

int main() {
	// NOTE: moved constants to the top

	srand(static_cast<unsigned>(time(nullptr)));

	benchmark(insertionSort, "Insertion Sort");

	benchmark(quickSort, "Quick Sort");

	// generate gap sequence to not be included in the benchmark
	auto gaps0 = gapSequence::A000225(N);
	auto shellSort0 = std::bind(shellSort, std::placeholders::_1, gaps0);
	benchmark(shellSort0, "Shell Sort (A000225 / Hibbard)");

	auto gaps1 = gapSequence::A003462(N);
	auto shellSort1 = std::bind(shellSort, std::placeholders::_1, gaps1);
	benchmark(shellSort1, "Shell Sort (A003462 / Knuth)");

	auto gaps2 = gapSequence::A108870(N);
	auto shellSort2 = std::bind(shellSort, std::placeholders::_1, gaps2);
	benchmark(shellSort2, "Shell Sort (A003462 / Tokuda)");

	benchmark(heapSort, "Heap Sort");

	return 0;
}

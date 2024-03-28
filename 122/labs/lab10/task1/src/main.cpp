#include "mergesort.cpp"
#include <iostream>
#include <vector>

int main() {
	std::vector<int> list = {4, 6, 7, 0, 2, 3, 5, 9, 8, 1};

	merge_sort(list);

	for (int &x : list)
		std::cout << x << " ";
	std::cout << std::endl;

	return 0;
}

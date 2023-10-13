#include "headers.h"

int sequential_search(int *arr, int size, int target) {
	for (int i = 0; i < size; ++i) {
		if (arr[i] == target)
			return i;
	}
	return -1;
}

int binary_search(int *arr, int size, int target) {
	int low = 0, high = size;

	while (low < high) {
		int mid = (low + high) / 2;

		if (arr[mid] >= target)
			high = mid;
		else
			low = mid + 1;
	}

	return arr[low] == target ? low : -1;
}

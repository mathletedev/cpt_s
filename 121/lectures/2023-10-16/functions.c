#include "headers.h"

void write_array(int *arr, int size) {
	for (int i = 0; i < size; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}

void selection_sort(int *arr, int size) {
	write_array(arr, size);

	for (int i = 0; i < size - 1; ++i) {
		int max_index = 0;

		for (int j = 1; j < size - i; ++j) {
			if (arr[j] > arr[max_index])
				max_index = j;
		}

		int tmp = arr[max_index];
		arr[max_index] = arr[size - i - 1];
		arr[size - i - 1] = tmp;

		sleep(1);
		write_array(arr, size);
	}
}

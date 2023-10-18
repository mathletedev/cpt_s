#include "headers.h"

void write_array(int *arr, int size) {
	for (int i = 0; i < size; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}

void bubble_sort(int *arr, int size) {
	write_array(arr, size);

	for (int i = 0; i < size - 1; ++i) {
		int changed = 0;
		for (int j = 0; j < size - i - 1; ++j) {
			if (arr[j] > arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;

				changed = 1;
			}
		}

		sleep(1);
		write_array(arr, size);

		if (!changed)
			break;
	}
}

#include "headers.h"

int read_array(FILE *infile, int *arr) {
	int data, index = 0;
	while (fscanf(infile, "%d", &data) != EOF)
		arr[index++] = data;

	return index;
}

void reverse_array(int *arr, size_t size) {
	for (int i = 0; i < size / 2; ++i) {
		int tmp = arr[i];
		arr[i] = arr[size - i - 1];
		arr[size - i - 1] = tmp;
	}
}

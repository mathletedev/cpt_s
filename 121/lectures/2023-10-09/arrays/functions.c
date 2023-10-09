#include "headers.h"

void print_array(int *arr, int size) {
	for (int index = 0; index < size; ++index)
		printf("arr[%d]: %d\n", index, arr[index]);
}

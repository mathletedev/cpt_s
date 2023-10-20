#include "headers.h"

int main(void) {
	FILE *infile = fopen("input.txt", "r");

	int arr[100] = {0};

	int num_read = read_array(infile, arr);

	reverse_array(arr, num_read);

	for (int i = 0; i < num_read; ++i)
		printf("%d\n", arr[i]);

	fclose(infile);

	return 0;
}

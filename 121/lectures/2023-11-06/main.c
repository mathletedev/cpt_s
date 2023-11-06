#include "headers.h"

int main(void) {
	int res = 0, m = 5, n = 4;

	res = multiply_iterative(m, n);
	printf("Iterative: %d\n", res);

	res = multiply_recursive(m, n);
	printf("Recursive: %d\n", res);

	return 0;
}

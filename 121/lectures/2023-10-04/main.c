#include "headers.h"

int main(void) {
	int n1 = 7, n2 = 3, result = 0, remainder = 0;

	divide(n1, n2, &result, &remainder);

	printf("result: %d\n", result);
	printf("remainder: %d\n", remainder);

	return 0;
}

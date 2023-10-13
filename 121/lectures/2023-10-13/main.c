#include "headers.h"

int main(void) {
	int ids[] = {1, 2, 3, 4, 5};

	printf("%d\n", sequential_search(ids, 5, 4));
	printf("%d\n", binary_search(ids, 5, 2));

	return 0;
}

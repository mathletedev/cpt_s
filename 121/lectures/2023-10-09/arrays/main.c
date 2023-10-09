#include "headers.h"

int main(void) {
	int ids[10] = {3, 1, 7, 5};
	int ids2[] = {3, 1, 7, 5};

	ids[2] = 9;

	print_array(ids, 10);

	return 0;
}

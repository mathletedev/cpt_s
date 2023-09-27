#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	// seed rng
	srand((unsigned int)time(NULL));

	// rand() will always return the same numbers, but
	// srand() will provide a different "starting point"
	printf("%d\n", rand() % 6 + 1);

	return 0;
}

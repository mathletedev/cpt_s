#include <stdio.h>

int main(void) {
	int count = 1; // initialisation expression

	while (count <= 10) { // repetition condition
		printf("count: %d\n", count);
		++count; // update expression
	}

	for (int i = 1 /* init expr */; i <= 10 /* rep cond */;
	     ++i /* update expr */) {
		printf("count: %d\n", i);
	}

	count = 1; // init expr
	do {
		printf("count: %d\n", count);
		++count;       // update expr
	} while (count <= 10); // rep cond

	return 0;
}

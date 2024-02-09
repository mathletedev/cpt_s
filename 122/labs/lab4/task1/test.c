#include "test.h"

void test_push(void) {
	Stack stack = {NULL};
	double data = 4.2;

	push(&stack, data);

	if (stack.top == NULL)
		puts("Test failed: Expected stack.top to be an address, found "
		     "NULL");
	else {
		if (stack.top->data != 4.2)
			printf("Test failed: Expected data = 4.2, found %lf\n",
			       stack.top->data);
		else
			puts("Test passed!");
	}
}

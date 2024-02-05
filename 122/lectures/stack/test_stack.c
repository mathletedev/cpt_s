#include "test_stack.h"

void test_push_on_empty_stack(void) {
	Stack s = {NULL};
	Data d = {'a'};

	int success = push(&s, d);
	if (success == 1)
		puts("Test passed");
	else
		puts("Test failed");
}

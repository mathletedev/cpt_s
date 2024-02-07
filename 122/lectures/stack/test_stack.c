#include "test_stack.h"

void test_push_on_empty_stack(void) {
	Stack stack = {NULL};
	Data data = {'a'};

	int success = push(&stack, data);
	if (success == 1)
		puts("Test passed");
	else
		puts("Test failed");
}

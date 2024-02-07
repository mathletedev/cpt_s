#include "functions.h"
#include "test_stack.h"

int main(void) {
	test_push_on_empty_stack();

	char *str = reverse_string("cat");
	printf("Reversed string: %s\n", str);

	return 0;
}

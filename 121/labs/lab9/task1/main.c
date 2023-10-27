#include "headers.h"

int main(void) {
	char my_string1[] = "CptS 121 is cool!";
	char my_string2[] = "CptS 121 is cool!";

	puts(string_reverse(my_string1));
	puts(string_reverse_pointer(my_string2));

	return 0;
}

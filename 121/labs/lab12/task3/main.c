#include "headers.h"

int main(void) {
	char string[] = "Reverse this string!";
	reverse(string, string + 19);

	puts(string);

	return 0;
}

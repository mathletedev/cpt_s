#include "headers.h"

int read_bool(char *prompt) {
	char bool;

invalid:;
	printf("%s? y/n: ", prompt);
	scanf(" %c", &bool);

	switch (bool) {
	case 'y':
		return 1;
	case 'n':
		return 0;
	default:
		printf("Invalid input: Must be 'y' or 'n'\n");
		goto invalid;
	}
}

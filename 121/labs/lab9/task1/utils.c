#include "headers.h"

char *string_reverse(char *string) {
	int size = 0;
	while (string[++size] != '\0')
		;

	for (int i = 0; i < size / 2; ++i) {
		char tmp = string[i];
		string[i] = string[size - 1 - i];
		string[size - 1 - i] = tmp;
	}

	return string;
}

char *string_reverse_pointer(char *string) {
	int size = 0;
	while (*(string + ++size) != '\0')
		;

	for (int i = 0; i < size / 2; ++i) {
		char tmp = *(string + i);
		*(string + i) = *(string + size - 1 - i);
		*(string + size - 1 - i) = tmp;
	}

	return string;
}

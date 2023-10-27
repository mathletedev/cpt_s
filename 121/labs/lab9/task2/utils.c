#include "headers.h"

char *my_strcpy(char *destination, const char *source) {
	for (int i = 0; source[i] != '\0'; ++i)
		destination[i] = source[i];

	return destination;
}

char *my_strcat(char *destination, const char *source) {
	int end = -1;
	while (destination[++end] != '\0')
		;

	int i = -1;
	do {
		++i;
		destination[end + i] = source[i];
	} while (source[i] != '\0');

	return destination;
}

int my_strcmp(const char *s1, const char *s2) {
	for (int i = 0;; ++i) {
		if (s1[i] == s2[i]) {
			if (s1[i] == '\0')
				return 0;
			continue;
		}

		return (s1[i] > s2[i]) * 2 - 1;
	}
}

int my_strlen(const char *s) {
	int size = 0;
	while (s[++size] != '\0')
		;

	return size;
}

#include "utils.h"

void clear(void) {
	// https://stackoverflow.com/a/36253316
#ifdef _WIN_32
	system("cls");
#else
	system("clear");
#endif
}

// waits for a key to be pressed
void suspend(void) {
	printf("Press any key to continue...");
	char c;
	scanf("%c", &c);
}

void consume_input(void) {
	for (char c; c != '\n'; scanf("%c", &c))
		;
}

// like strtok(), but takes quotes into account
char *next_tok(char *str, char delim) {
	static char *curr;
	if (str != NULL)
		curr = str;

	if (*curr == '"') {
		delim = '"';
		++curr;
	}

	while (*curr == ',') {
		++curr;
		if (*curr == '\0')
			return NULL;
	}

	char *beginning = curr;

	while (*curr != delim) {
		++curr;
		if (*curr == '\0')
			break;
	}
	*curr = '\0';
	++curr;

	return beginning;
}

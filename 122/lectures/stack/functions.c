#include "functions.h"

char *reverse_string(char *str) {
	Stack stack = {NULL};

	Data data = {'\0'};
	for (int i = 0; str[i] != '\0'; ++i) {
		data.letter = str[i];
		push(&stack, data);
	}

	for (int i = 0; !is_empty(&stack); pop(&stack), ++i) {
		data = peek(&stack);
		str[i] = data.letter;
	}

	return str;
}

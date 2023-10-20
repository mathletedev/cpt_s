#include "headers.h"

int main(void) {
	char word[] = SECRET_WORD;
	char guessed[] = SECRET_WORD;

	for (int i = 0; i < strlen(guessed); ++i)
		guessed[i] = '*';

	int incorrect = 0, correct = 0;
	int chars[26] = {0};

	while (1) {
		system("clear");

		printf("Word: %s\n\n", guessed);

		printf("Incorrect: %d / %d\n\n", incorrect, MAX_INCORRECT);

		printf("Characters: ");
		for (int i = 0; i < 26; ++i) {
			if (chars[i])
				printf("%c ", 'a' + i);
		}
		printf("\n\n");

		char c = '\0';
		do {
			if (c != '\0') {
				if (chars[c - 'a'])
					printf("You've already guessed that "
					       "character!\n");
				else
					printf(
					    "Enter a lowercase character!\n");
			}

			printf("Enter your guess: ");
			scanf(" %c", &c);

			printf("\n");
		} while (c < 'a' || c > 'z' || chars[c - 'a']);

		chars[c - 'a'] = 1;

		int found = 0;
		for (int i = 0; i < strlen(word); ++i) {
			if (c == word[i]) {
				guessed[i] = c;
				found = 1;
				++correct;
			}
		}

		if (!found)
			++incorrect;

		if (correct == strlen(word) || incorrect >= MAX_INCORRECT)
			break;
	}

	system("clear");

	if (incorrect >= MAX_INCORRECT)
		printf("You lost!\n\n");
	else
		printf("You won!\n\n");

	printf("The word was: %s\n", word);

	return 0;
}

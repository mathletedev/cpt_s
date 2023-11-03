#include "headers.h"

int main(void) {
	srand(time(NULL));

	char res[100];

	char *articles[] = {"the", "a", "one", "some", "any"};
	char *nouns[] = {"boy", "girl", "dog", "town", "car"};
	char *verbs[] = {"drove", "jumped", "ran", "walked", "skipped"};
	char *prepositions[] = {"to", "from", "over", "under", "on"};

	for (int i = 0; i < 20; ++i) {
		res[0] = '\0';

		strcat(res, get_rand(articles, 5));
		strcat(res, " ");
		strcat(res, get_rand(nouns, 5));
		strcat(res, " ");
		strcat(res, get_rand(verbs, 5));
		strcat(res, " ");
		strcat(res, get_rand(prepositions, 5));
		strcat(res, " ");
		strcat(res, get_rand(articles, 5));
		strcat(res, " ");
		strcat(res, get_rand(nouns, 5));
		strcat(res, "!");

		res[0] = toupper(res[0]);

		puts(res);
	}

	return 0;
}

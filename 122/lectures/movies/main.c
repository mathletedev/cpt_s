#include "headers.h"

int main(void) {
	FILE *infile = fopen("movies.csv", "r");
	if (infile == NULL) {
		puts("failed to open movies.csv");
		return 1;
	}

	char lines[MAX_ROWS][MAX_COLS];
	Node *head = NULL;
	int curr_line = 0;

	while (fgets(lines[curr_line], MAX_COLS, infile) != NULL) {
		printf("row %d: %s\n", curr_line, lines[curr_line]);
		++curr_line;
	}

	for (int i = 0; i < curr_line; ++i) {
		MovieRecord record;
		strcpy(record.title, strtok(lines[i], ","));
		record.year = atoi(strtok(NULL, "\n"));

		insert_front(&head, record);
	}

	print_list(head);

	return 0;
}

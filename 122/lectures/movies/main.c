#include "headers.h"

int main(void) {
	FILE *infile = fopen("movies.csv", "r");
	if (infile == NULL) {
		puts("failed to open movies.csv");
		return 1;
	}

	char lines[MAX_ROWS][MAX_COLS];
	MovieRecord records[MAX_ROWS];
	int curr_line = 0;

	while (fgets(lines[curr_line], MAX_COLS, infile) != NULL) {
		printf("row %d: %s\n", curr_line, lines[curr_line]);
		++curr_line;
	}

	for (int i = 0; i < curr_line; ++i) {
		strcpy(records[i].title, strtok(lines[i], ","));
		records[i].year = atoi(strtok(NULL, "\n"));
	}

	for (int i = 0; i < curr_line; ++i)
		printf("%s,%d\n", records[i].title, records[i].year);

	return 0;
}

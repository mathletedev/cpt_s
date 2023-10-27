#include "headers.h"

void init_board(char board[ROWS][COLS]) {
	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLS; ++j)
			board[i][j] = '~';
	}
}

void write_board(char board[ROWS][COLS]) {
	printf("    ");
	for (int i = 0; i < COLS; ++i)
		printf("%-4d", i);
	printf("\n");

	printf(BLUE);
	printf("  ╭");
	for (int i = 0; i < COLS - 1; ++i)
		printf("───┬");
	printf("───╮\n");

	for (int i = 0; i < ROWS; ++i) {
		if (i != 0) {
			printf("  ├");
			for (int j = 0; j < COLS - 1; ++j)
				printf("───┼");
			printf("───┤\n");
		}

		printf(RESET "%d " BLUE, i);
		for (int j = 0; j < COLS; ++j)
			printf("│%2c ", board[i][j]);
		printf("│\n");
	}

	printf("  ╰");
	for (int i = 0; i < COLS - 1; ++i)
		printf("───┴");
	printf("───╯\n");
	printf(RESET);
}

#include "headers.h"

void pause(void) {
	printf(GREEN "Press Enter to continue..." RESET);
	char c;
	scanf("%c", &c);
}

void clear(void) {
	// https://stackoverflow.com/a/36253316
#ifdef _WIN_32
	system("cls");
#else
	system("clear");
#endif
}

void welcome(void) {
	clear();

	printf(YELLOW);
	printf(
	    // clang-format off
			" ________         _____ _____ ______              ______  _____          \n"
			" ___  __ )______ ___  /___  /____  /_____ ___________  /_ ___(_)________ \n"
			" __  __  |_  __ `/_  __/_  __/__  / _  _ \\__  ___/__  __ \\__  / ___  __ \\\n"
			" _  /_/ / / /_/ / / /_  / /_  _  /  /  __/_(__  ) _  / / /_  /  __  /_/ /\n"
			" /_____/  \\__,_/  \\__/  \\__/  /_/   \\___/ /____/  /_/ /_/ /_/   _  .___/ \n"
			"                                                                /_/      \n"
	    // clang-format on
	);
	printf(RESET);
}

void init_board(Board *board) {
	for (int i = 0; i < board->rows; ++i) {
		for (int j = 0; j < board->cols; ++j)
			board->cells[i][j] = WATER;
	}
}

void write_board(Board board, int show_ships) {
	printf(CYAN "    ");
	for (int i = 0; i < board.cols; ++i)
		printf("%-4d", i);
	printf("\n");

	printf(BLUE);
	printf("  ╭");
	for (int i = 0; i < board.cols - 1; ++i)
		printf("───┬");
	printf("───╮\n");

	for (int i = 0; i < board.rows; ++i) {
		if (i != 0) {
			printf("  ├");
			for (int j = 0; j < board.cols - 1; ++j)
				printf("───┼");
			printf("───┤\n");
		}

		printf(CYAN "%d " BLUE, i);
		for (int j = 0; j < board.cols; ++j) {
			printf("│");
			if (board.cells[i][j] != WATER)
				printf(RESET);
			if (board.cells[i][j] == HIT)
				printf(RED);

			char state = board.cells[i][j];
			if (!show_ships && state != HIT && state != MISS)
				state = ' ';

			printf("%2c ", state);
			printf(BLUE);
		}
		printf("│\n");
	}

	printf("  ╰");
	for (int i = 0; i < board.cols - 1; ++i)
		printf("───┴");
	printf("───╯\n");
	printf(RESET);
}

void place_random(Board *board, int size, char ship) {
	while (1) {
		int dir = rand() % 2;

		Coordinates start;
		if (dir) {
			start.row = rand() % (board->rows - size);
			start.col = rand() % board->cols;
		} else {
			start.row = rand() % board->rows;
			start.col = rand() % (board->cols - size);
		}

		int possible = 1;
		for (int i = 0; i < size; ++i) {
			Coordinates curr = start;
			if (dir)
				curr.row += i;
			else
				curr.col += i;

			if (board->cells[curr.row][curr.col] != WATER)
				possible = 0;
		}

		if (!possible)
			continue;

		for (int i = 0; i < size; ++i) {
			Coordinates curr_pos = start;
			if (dir)
				curr_pos.row += i;
			else
				curr_pos.col += i;

			board->cells[curr_pos.row][curr_pos.col] = ship;
		}

		break;
	}
}

void warn_invalid(void) { printf(RED "🚨 Invalid input\n" RESET); }

void consume_input(void) {
	for (char c; c != '\n'; scanf("%c", &c))
		;
}

int read_coordinates(Coordinates *coords, Board board) {
	int valid = 1;
	if (scanf("%d%d", &coords->row, &coords->col) != 2)
		valid = 0;
	if (coords->row < 0 || coords->row >= board.rows || coords->col < 0 ||
	    coords->col >= board.cols)
		valid = 0;
	char state = board.cells[coords->row][coords->col];
	if (state == HIT || state == MISS)
		valid = 0;

	return valid;
}

#include "headers.h"

void wait_for_keypress(void) {
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

			char state = board.cells[i][j];
			switch (state) {
			case HIT:
				printf(RED);
				break;
			case MISS:
				printf(GREEN);
				break;
			case WATER:
				printf(BLUE);
				break;
			default:
				printf(RESET);
				break;
			}

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
	if (check_shot(*coords, board) == -1)
		valid = 0;

	return valid;
}

int check_shot(Coordinates target, Board board) {
	int state = board.cells[target.row][target.col];

	if (state == HIT || state == MISS)
		return -1;
	return state != WATER;
}

char take_shot(Coordinates target, Board *board, Stats *stats) {
	char ship = board->cells[target.row][target.col];

	int hit = check_shot(target, *board);
	board->cells[target.row][target.col] = hit ? HIT : MISS;

	printf(CYAN "%s %d, %d" GREEN " is a %s!\n", hit ? "💥" : "💬",
	       target.row, target.col, hit ? "hit" : "miss");
	NEWLINE;

	++stats->total;
	if (hit)
		++stats->hits;
	else
		++stats->misses;
	stats->percentage = ((double)stats->hits / stats->total) * 100;

	return ship;
}

Coordinates random_target(Board board) {
	Coordinates target;

	while (1) {
		int row = rand() % board.rows;
		int col = rand() % board.cols;

		target.row = row;
		target.col = col;

		if (check_shot(target, board) != -1)
			break;
	}

	return target;
}

int ship_to_int(char ship) {
	switch (ship) {
	case 'c':
		return 0;
	case 'b':
		return 1;
	case 'r':
		return 2;
	case 's':
		return 3;
	case 'd':
		return 4;
	}

	return -1;
}

char *ship_to_name(char ship) {
	switch (ship) {
	case 'c':
		return "Carrier";
	case 'b':
		return "Battleship";
	case 'r':
		return "Cruiser";
	case 's':
		return "Submarine";
	case 'd':
		return "Destroyer";
	}

	return "";
}

void update_frequency(int *frequency, Board board) {
	for (int i = 0; i < 5; ++i)
		frequency[i] = 0;

	for (int i = 0; i < board.rows; ++i) {
		for (int j = 0; j < board.cols; ++j) {
			int index = ship_to_int(board.cells[i][j]);
			if (index == -1)
				continue;

			++frequency[index];
		}
	}
}

int check_sunk(char ship, int *frequency) {
	int index = ship_to_int(ship);
	if (index == -1)
		return 0;

	return !frequency[index];
}

void write_sunk(char ship) {
	printf(RED "💣 Sunk %s!\n" RESET, ship_to_name(ship));
	NEWLINE;
}

void write_move(FILE *logfile, int player, Coordinates target, int hit,
		char sunk) {
	fprintf(logfile, "Player %d: %d, %d \"%s\"%s%s%s\n", player + 1,
		target.row, target.col, hit ? "hit" : "miss",
		sunk == ' ' ? "" : " Sunk ", ship_to_name(sunk),
		sunk == ' ' ? "" : "!");
	fflush(logfile);
}

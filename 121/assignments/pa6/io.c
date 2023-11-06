#include "io.h"

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

void warn_invalid(void) { printf(RED "🚨 Invalid input\n" RESET); }

void consume_input(void) {
	for (char c; c != '\n'; scanf("%c", &c))
		;
}

void welcome(void) {
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
	// rules written with the help of ChatGPT
	puts("Battleship Rules:");
	NEWLINE;
	puts("1. Each player has a 10x10 grid.");
	NEWLINE;
	puts("2. Place your ships on the grid without overlapping or extending "
	     "off the board.");
	NEWLINE;
	puts("3. Take turns guessing coordinates to try to hit your opponent's "
	     "ships.");
	NEWLINE;
	puts("4. If a guess hits, it is marked with a \"*\". Otherwise, "
	     "it is marked with a \"m\".");
	NEWLINE;
	puts("5. The game ends when all of one player's ships are sunk.");
	NEWLINE;
	puts("6. Good luck and have fun!");
	NEWLINE;
	printf(RESET);
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

void write_shot(Coordinates target, int hit) {
	printf(CYAN "%s %d, %d" GREEN " is a %s!\n", hit ? "💥" : "💬",
	       target.row, target.col, hit ? "hit" : "miss");
	NEWLINE;
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

void write_stats(FILE *logfile, int player, Stats stats) {
	fprintf(logfile, "**** Player %d's Stats ****\n", player);
	fprintf(logfile, "Hits: %d\n", stats.hits);
	fprintf(logfile, "Misses: %d\n", stats.misses);
	fprintf(logfile, "Total shots: %d\n", stats.total);
	fprintf(logfile, "Hit/miss ratio: %d%%\n", stats.percentage);

	fflush(logfile);
}

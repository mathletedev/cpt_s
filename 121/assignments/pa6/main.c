#include "headers.h"

int main(void) {
	srand(time(NULL));
	FILE *logfile = fopen("battleship.log", "w");

	int curr_player = rand() % 2;

	Stats p1_stats = {0, 0, 0, 0, 0};
	Stats p2_stats = {0, 0, 0, 0, 0};

	Board p1_board;
	p1_board.rows = ROWS;
	p1_board.cols = COLS;
	init_board(&p1_board);
	Board p2_board;
	p2_board.rows = ROWS;
	p2_board.cols = COLS;
	init_board(&p2_board);

	int p1_frequency[5] = {0};
	int p2_frequency[5] = {0};

	welcome();
	wait_for_keypress();

	place_random(&p1_board, 5, 'c');
	place_random(&p1_board, 4, 'b');
	place_random(&p1_board, 3, 'r');
	place_random(&p1_board, 3, 's');
	place_random(&p1_board, 2, 'd');

	place_random(&p2_board, 5, 'c');
	place_random(&p2_board, 4, 'b');
	place_random(&p2_board, 3, 'r');
	place_random(&p2_board, 3, 's');
	place_random(&p2_board, 2, 'd');

	while (1) {
		clear();

		printf(YELLOW "🚢 Player 1's board\n");
		NEWLINE;
		write_board(p1_board, 1);
		NEWLINE;
		printf(YELLOW "🔎 Player 2's board\n");
		NEWLINE;
		write_board(p2_board, 0);
		NEWLINE;

		if (curr_player == HUMAN) {
			Coordinates target;
			while (1) {
				printf(MAGENTA "🎯 Enter a target: " RESET);
				if (read_coordinates(&target, p2_board))
					break;
				else {
					consume_input();
					warn_invalid();
				}
			}
			consume_input();

			NEWLINE;

			char ship = take_shot(target, &p2_board, &p1_stats);
			update_frequency(p2_frequency, p2_board);
			int sunk = check_sunk(ship, p2_frequency);
			if (sunk)
				write_sunk(ship);
			write_move(logfile, curr_player, target, ship != WATER,
				   sunk ? ship : ' ');
		} else {
			Coordinates target = random_target(p1_board);
			printf(MAGENTA "🎯 Computer selects: " RESET "...");
			fflush(stdout);
			sleep(1);

			printf(MAGENTA "\r🎯 Computer selects: " RESET "%d %d\n",
			       target.row, target.col);

			NEWLINE;

			char ship = take_shot(target, &p1_board, &p2_stats);
			update_frequency(p1_frequency, p1_board);
			int sunk = check_sunk(ship, p1_frequency);
			if (sunk)
				write_sunk(ship);
			write_move(logfile, curr_player, target, ship != WATER,
				   sunk ? ship : ' ');
		}

		curr_player = !curr_player;

		wait_for_keypress();
	}

	fclose(logfile);

	return 0;
}

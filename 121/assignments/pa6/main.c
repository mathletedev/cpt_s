#include "headers.h"

int main(void) {
	srand(time(NULL));
	FILE *logfile = fopen("battleship.log", "w");

	int curr_player = 0;

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

	welcome();
	pause();

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

		if (curr_player) {
			Coordinates target = {0, 0};
			p1_board.cells[target.row][target.col] = HIT;
		} else {
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

			if (p2_board.cells[target.row][target.col] != WATER)
				p2_board.cells[target.row][target.col] = HIT;
			else
				p2_board.cells[target.row][target.col] = MISS;
		}

		curr_player = !curr_player;
	}
}

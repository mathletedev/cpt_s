#include "utils.h"
#include "helpers.h"
#include "io.h"

void init_board(Board *board) {
	for (int i = 0; i < board->rows; ++i) {
		for (int j = 0; j < board->cols; ++j)
			board->cells[i][j] = WATER;
	}
}
void place_random_one(Board *board, int size, char ship, int *ships) {
	ships[ship - 'a'] = size;

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

void place_random_all(Board *board, int *ships) {
	place_random_one(board, 5, 'c', ships);
	place_random_one(board, 4, 'b', ships);
	place_random_one(board, 3, 'r', ships);
	place_random_one(board, 3, 's', ships);
	place_random_one(board, 2, 'd', ships);
}

void place_manual_one(Board *board, int size, char ship, int *ships) {
	ships[ship - 'a'] = size;

	Coordinates coords[5];
	while (1) {
		printf(MAGENTA "🚢 Enter " CYAN "%d" MAGENTA
			       " cells to place the " CYAN "%s" MAGENTA
			       " across: " RESET,
		       size, ship_to_name(ship));

		int valid = 1;
		for (int i = 0; i < size; ++i) {
			if (!read_coordinates(coords + i, *board) ||
			    board->cells[coords[i].row][coords[i].col] !=
				WATER) {
				valid = 0;
				break;
			}
		}

		if (!valid) {
			consume_input();
			warn_invalid();
			continue;
		}
		consume_input();

		NEWLINE;

		int horizontal = 1, vertical = 1;
		int cols[COLS] = {0}, rows[ROWS] = {0};
		for (int i = 0; i < size; ++i) {
			cols[coords[i].col] = 1;
			rows[coords[i].row] = 1;

			if (i == 0)
				continue;

			if (coords[i].row != coords[0].row)
				horizontal = 0;
			if (coords[i].col != coords[0].col)
				vertical = 0;
		}

		if (!horizontal && !vertical) {
			warn_invalid();
			continue;
		}

		int *frequency = horizontal ? cols : rows;
		int start = -1, end = -1;
		for (int i = 0; i < ROWS; ++i) {
			if (frequency[i] && start == -1)
				start = i;
			if (!frequency[i] && start != -1) {
				end = i;
				break;
			}
		}
		if (end == -1)
			end = ROWS;

		if (end - start == size)
			break;
		else
			warn_invalid();
	}

	for (int i = 0; i < size; ++i)
		board->cells[coords[i].row][coords[i].col] = ship;
}

void place_manual_all(Board *board, int *ships) {
	place_manual_one(board, 5, 'c', ships);
	place_manual_one(board, 4, 'b', ships);
	place_manual_one(board, 3, 'r', ships);
	place_manual_one(board, 3, 's', ships);
	place_manual_one(board, 2, 'd', ships);
}

void take_shot(Coordinates target, Board *board, Stats *stats, char *ship_ptr,
	       int *hit_ptr) {
	*ship_ptr = board->cells[target.row][target.col];
	*hit_ptr = check_shot(target, *board);

	board->cells[target.row][target.col] = *hit_ptr ? HIT : MISS;

	++stats->total;
	if (*hit_ptr)
		++stats->hits;
	else
		++stats->misses;
	stats->percentage = round(((double)stats->hits / stats->total) * 100);
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

int check_lost(int *ships) {
	int lost = 1;
	for (int i = 0; i < 26; ++i) {
		if (ships[i])
			lost = 0;
	}

	return lost;
}

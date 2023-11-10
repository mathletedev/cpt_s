#include "utils.h"
#include "helpers.h"
#include "io.h"

/*
 * Initialises a game board
 *
 * Parameters:
 * - Board *board: Pointer to returned board
 *
 * Post-conditions: Board will be filled with WATER characters
 */
void init_board(Board *board) {
	for (int i = 0; i < board->rows; ++i) {
		for (int j = 0; j < board->cols; ++j)
			board->cells[i][j] = WATER;
	}
}

/*
 * Places a random ship on a game board
 *
 * Parameters:
 * - Board *board: Pointer to returned board
 * - int size: Size of ship
 * - char ship: Type of ship
 * - int *ships: Pointer to returned frequency array
 *
 * Post-conditions: A ship of size size and type ship will be added to the board
 */
void place_random_one(Board *board, int size, char ship, int *ships) {
	// set frequency of ship
	ships[ship - 'a'] = size;

	while (1) {
		// 0 = horizontal ship, 1 = vertical ship
		int dir = rand() % 2;

		Coordinates start;
		if (dir) {
			// adjust for borders of board
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

			// ship is overlapping
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

			// assign ship to board
			board->cells[curr_pos.row][curr_pos.col] = ship;
		}

		break;
	}
}

/*
 * Places all ships on board randomly
 *
 * Parameters:
 * - Board *board: Pointer to returned board
 * - int *ships: Pointer to returned frequency array
 *
 * Post-conditions: All ships will be placed on board randomly
 */
void place_random_all(Board *board, int *ships) {
	place_random_one(board, 5, 'c', ships);
	place_random_one(board, 4, 'b', ships);
	place_random_one(board, 3, 'r', ships);
	place_random_one(board, 3, 's', ships);
	place_random_one(board, 2, 'd', ships);
}

// Refer to place_random_one()
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
		// if all rows match or all columns match, that is the direction
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
		// find length of contiguous 1s
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

		// length should be equal to size
		if (end - start == size)
			break;
		else
			warn_invalid();
	}

	for (int i = 0; i < size; ++i)
		board->cells[coords[i].row][coords[i].col] = ship;
}

// Refer to place_random_all()
void place_manual_all(Board *board, int *ships) {
	place_manual_one(board, 5, 'c', ships);
	place_manual_one(board, 4, 'b', ships);
	place_manual_one(board, 3, 'r', ships);
	place_manual_one(board, 3, 's', ships);
	place_manual_one(board, 2, 'd', ships);
}

/*
 * Takes a shot at the enemy board
 *
 * Parameters:
 * - Coordinates target: Player's target
 * - Board *board: Pointer to returned board
 * - Stats *stats: Pointer to returned stats
 * - char *ship_ptr: Pointer to returned type of ship
 * - char *hit_ptr: Pointer to returned hit variable
 *
 * Post-conditions: Board will be updated with new shot
 */
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

/*
 * Selects a random target
 *
 * Parameters:
 * - Board board: Enemy's board
 *
 * Returns a random coordinate that has not been targeted yet
 */
Coordinates random_target(Board board) {
	Coordinates target;

	while (1) {
		int row = rand() % board.rows;
		int col = rand() % board.cols;

		target.row = row;
		target.col = col;

		// check that target is new
		if (check_shot(target, board) != -1)
			break;
	}

	return target;
}

/*
 * Checks if a player lost
 *
 * Parameters:
 * - int *ships: Player's frequency array
 *
 * Returns 1 if the player lost
 */
int check_lost(int *ships) {
	int lost = 1;
	for (int i = 0; i < 26; ++i) {
		if (ships[i])
			lost = 0;
	}

	return lost;
}

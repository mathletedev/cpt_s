#include "helpers.h"

/*
 * Converts a character ship type to its associated name
 *
 * Parameters:
 * - char ship: Type of ship
 *
 * Returns the associated name
 */
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

/*
 * Checks if a target hit a ship
 *
 * Parameters:
 * - Coordinates target: Player's target
 * - Board board: Enemy's board
 *
 * Returns:
 * - -1 if target has already been hit
 * - 0 if target hit water
 * - 1 if target hit a ship
 */
int check_shot(Coordinates target, Board board) {
	int state = board.cells[target.row][target.col];

	if (state == HIT || state == MISS)
		return -1;
	return state != WATER;
}

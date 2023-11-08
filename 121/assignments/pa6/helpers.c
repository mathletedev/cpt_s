#include "helpers.h"

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

int check_shot(Coordinates target, Board board) {
	int state = board.cells[target.row][target.col];

	if (state == HIT || state == MISS)
		return -1;
	return state != WATER;
}

#include "headers.h"

int main(void) {
	char board[ROWS][COLS];

	init_board(board);

	write_board(board);
}

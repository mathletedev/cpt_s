#include "headers.h"

int main(void) {
	srand(time(NULL));

	Cell board[N][N];
	init_board(board);

	int turn = rand() % 2;
	char winner;

	while (1) {
		clear();
		write_board(board);

		if (turn) {
			printf("> ...");
			fflush(stdout);
			sleep(1);

			ai(board);

			printf("Press Enter to continue...");
			char c;
			scanf("%c", &c);
		} else {
			int row, column, valid = 1;
			do {
				if (!valid)
					puts("Invalid input");

				printf("> ");
				scanf("%d%d", &row, &column);
				--row, --column;

				valid = 0;
				consume_input();
			} while (row < 0 || row > 2 || column < 0 ||
				 column > 2 || board[row][column].occupied);

			board[row][column].symbol = 'X';
			board[row][column].occupied = 1;
		}

		turn = !turn;

		winner = check_winner(board);
		if (winner != ' ')
			break;

		if (is_full(board))
			break;
	}

	clear();
	write_board(board);

	if (winner == 'X')
		puts("You won!");
	else if (winner == 'O')
		puts("Computer won!");
	else
		puts("It's a tie!");

	return 0;
}

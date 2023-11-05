#include "headers.h"

void clear(void) {
#ifdef _WIN_32
	system("cls");
#else
	system("clear");
#endif
}

void consume_input(void) {
	for (char c; c != '\n'; scanf("%c", &c))
		;
}

void init_board(Cell board[N][N]) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			board[i][j].occupied = 0;
			board[i][j].symbol = ' ';
			Coordinate location = {i, j};
			board[i][j].location = location;
		}
	}
}

void write_board(Cell board[N][N]) {
	printf("    ");
	for (int i = 1; i <= N; ++i)
		printf("%-4d", i);
	printf("\n");

	printf("  ╭");
	for (int i = 0; i < N - 1; ++i)
		printf("───┬");
	printf("───╮\n");

	for (int i = 0; i < N; ++i) {
		if (i != 0) {
			printf("  ├");
			for (int j = 0; j < N - 1; ++j)
				printf("───┼");
			printf("───┤\n");
		}

		printf("%d ", i + 1);

		for (int j = 0; j < N; ++j) {
			printf("│");

			printf("%2c ", board[i][j].symbol);
		}
		printf("│\n");
	}

	printf("  ╰");
	for (int i = 0; i < N - 1; ++i)
		printf("───┴");
	printf("───╯\n");
}

char check_winner(Cell board[N][N]) {
	char cmp = ' ';

	for (int i = 0; i < N; ++i) {
		if (!board[i][0].occupied)
			break;

		cmp = board[i][0].symbol;
		for (int j = 1; j < N; ++j) {
			if (board[i][j].symbol != cmp) {
				cmp = ' ';
				break;
			}
		}

		if (cmp != ' ')
			return cmp;
	}

	for (int i = 0; i < N; ++i) {
		if (!board[0][i].occupied)
			break;

		cmp = board[0][i].symbol;
		for (int j = 1; j < N; ++j) {
			if (board[j][i].symbol != cmp) {
				cmp = ' ';
				break;
			}
		}

		if (cmp != ' ')
			return cmp;
	}

	cmp = board[0][0].symbol;
	for (int i = 1; i < N; ++i) {
		if (!board[0][0].occupied)
			break;

		if (board[i][i].symbol != cmp) {
			cmp = ' ';
			break;
		}
	}
	if (cmp != ' ')
		return cmp;

	cmp = board[N - 1][0].symbol;
	for (int i = 1; i < N; ++i) {
		if (!board[N - 1][0].occupied)
			break;

		if (board[N - 1 - i][i].symbol != cmp) {
			cmp = ' ';
			break;
		}
	}
	if (cmp != ' ')
		return cmp;

	return ' ';
}

int is_full(Cell board[N][N]) {
	int res = 1;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (!board[i][j].occupied)
				res = 0;
		}
	}

	return res;
}

int minimax(Cell board[N][N], int turn) {
	char winner = check_winner(board);
	if (winner == 'X')
		return -1;
	if (winner == 'O')
		return 1;

	if (is_full(board))
		return 0;

	int best = 1e9 * turn;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (board[i][j].occupied)
				continue;

			board[i][j].symbol = turn == 1 ? 'X' : 'O';
			board[i][j].occupied = 1;

			int res = minimax(board, turn * -1);
			if (turn == -1) {
				if (res > best)
					best = res;
			} else {
				if (res < best)
					best = res;
			}

			board[i][j].symbol = ' ';
			board[i][j].occupied = 0;
		}
	}

	return best;
}

void ai(Cell board[3][3]) {
	int best = -1e9;
	int row = 0, column = 0;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (board[i][j].occupied)
				continue;

			board[i][j].symbol = 'O';
			board[i][j].occupied = 1;

			int res = minimax(board, 1);
			if (res > best || (res == best && rand() % 2)) {
				best = res;

				row = i;
				column = j;
			}

			board[i][j].symbol = ' ';
			board[i][j].occupied = 0;
		}
	}

	board[row][column].symbol = 'O';
	board[row][column].occupied = 1;

	printf("\r> %d %d\n", row + 1, column + 1);
}

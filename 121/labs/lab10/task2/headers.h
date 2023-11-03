#ifndef HEADERS_H
#define HEADERS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN_32
#include <Windows.h>
#define sleep Sleep
#else
#include <unistd.h>
#endif

#define N 3

typedef struct coordinate {
	int row;
	int column;
} Coordinate;

typedef struct cell {
	int occupied;
	char symbol;
	Coordinate location;
} Cell;

void clear(void);
void consume_input(void);
void init_board(Cell board[N][N]);
void write_board(Cell board[N][N]);
char check_winner(Cell board[N][N]);
int is_full(Cell board[N][N]);
int minimax(Cell board[N][N], int turn);
void ai(Cell board[N][N]);

#endif

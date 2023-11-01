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

#define ROWS 10
#define COLS 10

// ANSI colour codes for cool text
// https://stackoverflow.com/questions/3219393/stdlib-and-colored-output-in-c
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"

#define WATER ' '
#define HIT '*'
#define MISS 'm'

#define HUMAN 0
#define AI 1

#define NEWLINE printf("\n")

typedef struct Stats {
	int hits;
	int misses;
	int total;
	int percentage;
	int won;
} Stats;

typedef struct Coordinates {
	int row;
	int col;
} Coordinates;

typedef struct Board {
	char cells[ROWS][COLS];
	size_t rows;
	size_t cols;
} Board;

void wait_for_keypress(void);
void clear(void);

void welcome(void);

void init_board(Board *board);
void write_board(Board board, int show_ships);
void place_random(Board *board, int size, char ship);

void warn_invalid(void);
void consume_input(void);
int read_coordinates(Coordinates *coords, Board board);

int check_shot(Coordinates target, Board board);
char take_shot(Coordinates target, Board *board, Stats *stats);
Coordinates random_target(Board board);

int ship_to_int(char ship);
char *ship_to_name(char ship);
void update_frequency(int *frequency, Board board);
int check_sunk(char ship, int *frequency);
void write_sunk(char ship);

void write_move(FILE *logfile, int player, Coordinates target, int hit,
		char sunk);

#endif

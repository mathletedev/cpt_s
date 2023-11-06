#ifndef GLOBALS_H
#define GLOBALS_H

#include <stdlib.h>
#include <time.h>

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

// make it clearer what certain values mean
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
} Stats;

// store pairs of coodinates together
typedef struct Coordinates {
	int row;
	int col;
} Coordinates;

// store rows and cols along with board for easy access
typedef struct Board {
	char cells[ROWS][COLS];
	int rows;
	int cols;
} Board;

#endif

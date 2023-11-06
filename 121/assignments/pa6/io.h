#ifndef IO_H
#define IO_H

#include <stdio.h>

#include "globals.h"
#include "helpers.h"

void wait_for_keypress(void);
void clear(void);

void warn_invalid(void);
void consume_input(void);

void write_board(Board board, int show_ships);

void welcome(void);

int read_coordinates(Coordinates *coords, Board board);

void write_shot(Coordinates target, int hit);
void write_sunk(char ship);
void write_move(FILE *logfile, int player, Coordinates target, int hit,
		char sunk);

void write_stats(FILE *logfile, int player, Stats stats);

#endif

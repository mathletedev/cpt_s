#ifndef UTILS_H
#define UTILS_H

#include <math.h>

#include "globals.h"
#include "helpers.h"

void init_board(Board *board);

void place_random_one(Board *board, int size, char ship);
void place_random_all(Board *board);

void place_manual_one(Board *board, int size, char ship);
void place_manual_all(Board *board);

void take_shot(Coordinates target, Board *board, Stats *stats, char *ship_ptr,
	       int *hit_ptr);
Coordinates random_target(Board board);

void update_frequency(int *frequency, Board board);
int check_sunk(char ship, int *frequency);
int check_lost(int *frequency);

#endif

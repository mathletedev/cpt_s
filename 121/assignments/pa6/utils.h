/*
 * Name: Neal Wang
 * Due Date: 2023-11-10
 * Lecture: 02
 * Lab: 25
 * Assignment: PA 6
 * Description: Header file for utils.c
 */

#ifndef UTILS_H
#define UTILS_H

#include <math.h>

#include "globals.h"
#include "helpers.h"

void init_board(Board *board);

void place_random_one(Board *board, int size, char ship, int *ships);
void place_random_all(Board *board, int *ships);

void place_manual_one(Board *board, int size, char ship, int *ships);
void place_manual_all(Board *board, int *ships);

void take_shot(Coordinates target, Board *board, Stats *stats, char *ship_ptr,
	       int *hit_ptr);
Coordinates random_target(Board board);

int check_lost(int *ships);

#endif

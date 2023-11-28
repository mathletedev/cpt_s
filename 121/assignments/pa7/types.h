/*
 * Name: Neal Wang
 * Due Date: 2023-11-29
 * Lecture: 02
 * Lab: 25
 * Assignment: PA 7
 * Description: Structs and enums
 */

#ifndef TYPES_H
#define TYPES_H

#include "constants.h"

typedef struct card {
	int face;
	int suit;
} Card;

typedef struct hand {
	Card cards[NUM_CARDS];
} Hand;

// enum for strength of a hand (based on combinations)
// higher enum = larger number = stronger hand
typedef enum strength {
	SINGLE,
	PAIR,
	TWO_PAIRS,
	THREE,
	STRAIGHT,
	FLUSH,
	FULL,
	FOUR,
	STRAIGHT_FLUSH
} Strength;

#endif

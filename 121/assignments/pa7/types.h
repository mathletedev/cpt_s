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

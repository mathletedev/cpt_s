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

#endif

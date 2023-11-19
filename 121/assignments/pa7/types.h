#ifndef TYPES_H
#define TYPES_H

typedef struct card {
	int face;
	int suit;
} Card;

typedef struct hand {
	Card cards[5];
} Hand;

#endif

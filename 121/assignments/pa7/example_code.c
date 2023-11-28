#include "example_code.h"

// modified from Deitel & Deitel example code

/* shuffle cards in deck */
void shuffle(int *deck) {
	// position of card
	int pos = 0;

	/* for each of the 52 cards, choose slot of deck randomly */
	for (int card = 0; card < 52; card++) {
		/* choose new random location until unoccupied slot found */
		do {
			pos = rand() % 52;
		} while (deck[pos] != -1);

		/* place card number in chosen slot of deck */
		deck[pos] = card;
	}
}

// complete rewrite of deal function
void deal(Hand *hand, int *deck, int *seed, int mask) {
	for (int i = 0; i < 5; ++i) {
		// check if bit in bitmask is set
		if ((mask & (1 << i)) == 0)
			continue;

		int card = deck[*seed];
		// face from 0-12
		hand->cards[i].face = card % 13;
		// suit from 0-3
		hand->cards[i].suit = card / 13;

		++*seed;
	}
}

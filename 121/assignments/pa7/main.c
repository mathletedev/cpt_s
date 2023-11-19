#include "headers.h"

int main(void) {
	srand((unsigned)time(NULL));

	int deck[52];

	Hand *dealer = malloc(sizeof(Hand));
	Hand *player = malloc(sizeof(Hand));

	while (1) {
		for (int i = 0; i < 52; ++i)
			deck[i] = -1;
		shuffle(deck);

		int seed = 0;
		// set all bits in bitmask: 100000 - 1 = 11111
		deal(dealer, deck, &seed, (1 << 5) - 1);
		deal(player, deck, &seed, (1 << 5) - 1);

		write_hand(*dealer, 0);
		write_hand(*player, 1);

		wait_for_enter();
	}

	free(dealer);
	free(player);

	return 0;
}

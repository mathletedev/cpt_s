#include "headers.h"
#include "utils.h"

int main(void) {
	srand((unsigned)time(NULL));

	int deck[52];

	Hand *dealer = malloc(sizeof(Hand));
	Hand *player = malloc(sizeof(Hand));

	// store input validity
	int valid;
	// store error message of invalid input
	char message[MESSAGE_SIZE];

	while (1) {
		clear();
		NEWLINE;

		// initialise deck
		for (int i = 0; i < 52; ++i)
			deck[i] = -1;
		shuffle(deck);

		int seed = 0;
		// set all bits in bitmask: 100000 - 1 = 11111
		deal(dealer, deck, &seed, (1 << 5) - 1);
		deal(player, deck, &seed, (1 << 5) - 1);

		/* write_hand(*dealer, 0, 1); */
		/* NEWLINE; */
		write_hand(*player, 1, 1);
		NEWLINE;

		// mostly copied from PA 5
		valid = 1;
		// bitmask for redraw
		int mask = 0;
		do {
			// reset mask
			mask = 0;

			if (!valid) {
				clear();
				NEWLINE;

				write_hand(*player, 1, 1);
				NEWLINE;
			}

			printf(MAGENTA);
			puts("🃏 Enter up to 3 cards to re-draw (no spaces)");
			puts("   Enter a 0 if you do not want to re-draw");
			printf(RESET);
			NEWLINE;

			if (!valid) {
				warn(message);
				NEWLINE;
			}

			printf(" > ");

			valid = 0;

			int num;
			int num_read = scanf("%d", &num);
			consume_input();
			NEWLINE;

			// invalid cases
			if (num_read != 1) {
				strncpy(message,
					"Input must be a single integer",
					MESSAGE_SIZE);
				continue;
			}
			if (num < 0) {
				strncpy(message, "Input must be positive",
					MESSAGE_SIZE);
				continue;
			}
			if (num > 999) {
				strncpy(message,
					"Input must be at most 3 digits",
					MESSAGE_SIZE);
				continue;
			}

			if (num == 0) {
				valid = 1;
				break;
			}

			// validate redraw
			while (num > 0) {
				int digit = num % 10;
				if (digit == 0 || digit > NUM_CARDS) {
					strncpy(
					    message,
					    "Input must only contain digits "
					    "from 1 to 5",
					    MESSAGE_SIZE);
					goto skip;
				}
				--digit;
				// use bit math to check validity
				if (mask != (mask & ~(1 << digit))) {
					strncpy(message,
						"Cannot re-draw the same card",
						MESSAGE_SIZE);
					goto skip;
				}
				mask |= 1 << digit;
				num /= 10;
			}

			valid = 1;
		skip:;
		} while (!valid);

		deal(player, deck, &seed, mask);

		clear();
		NEWLINE;

		puts(CYAN "🃏 Dealer's hand" RESET);
		write_hand(*dealer, 1, 0);
		NEWLINE;
		puts(CYAN "🃏 Your hand" RESET);
		write_hand(*player, 1, 0);
		NEWLINE;

		wait_for_enter();
	}

	free(dealer);
	free(player);

	return 0;
}

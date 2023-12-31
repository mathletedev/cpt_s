#include "headers.h"

int main(void) {
	srand((unsigned)time(NULL));

	int deck[52];

	Hand *dealer_hand = malloc(sizeof(Hand));
	Hand *player_hand = malloc(sizeof(Hand));

	// store input validity
	int valid;
	// store error message of invalid input
	char message[MESSAGE_SIZE];

	while (1) {
		int choice = menu();

		if (choice == 3)
			break;
		if (choice == 1) {
			rules();
			wait_for_enter();
			continue;
		}

		// initialise deck
		for (int i = 0; i < 52; ++i)
			deck[i] = -1;
		shuffle(deck);

		// seed for dealing, increment to avoid duplicates
		int seed = 0;
		// set all bits in bitmask: 100000 - 1 = 11111
		deal(dealer_hand, deck, &seed, (1 << 5) - 1);
		deal(player_hand, deck, &seed, (1 << 5) - 1);

		clear();
		NEWLINE;

		puts(GREEN "💾 Dealer's turn" RESET);
		NEWLINE;
		write_hand(dealer_hand, 0, 1);
		NEWLINE;

		int ai_mask = ai(dealer_hand);

		puts(MAGENTA "🃏 Dealer re-draws:" RESET);
		NEWLINE;

		printf(" > ...");
		fflush(stdout);
		sleep(1);
		printf("\r > ");

		if (ai_mask == 0)
			printf("0");
		else {
			for (int i = 0; i < NUM_CARDS; ++i) {
				// print dealer's choices
				// will be > 0 if 1 at position
				if (ai_mask & 1 << i)
					printf("%d", i + 1);
			}
		}
		// clear ...
		printf("   ");
		NEWLINE;
		NEWLINE;

		wait_for_enter();

		// AI dealer bitmask
		deal(dealer_hand, deck, &seed, ai(dealer_hand));

		clear();
		NEWLINE;

		puts(GREEN "👤 Player's turn" RESET);
		NEWLINE;
		write_hand(player_hand, 1, 1);
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

				puts(GREEN "👤 Player's turn" RESET);
				NEWLINE;
				write_hand(player_hand, 1, 1);
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
				// will be > 0 if 1 at position
				if (mask & 1 << digit) {
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

		deal(player_hand, deck, &seed, mask);

		clear();
		NEWLINE;

		int w = winner(dealer_hand, player_hand);

		puts(CYAN "  Dealer's hand" RESET);
		write_hand(dealer_hand, 1, 0);
		NEWLINE;
		puts(CYAN "  Your hand" RESET);
		write_hand(player_hand, 1, 0);
		NEWLINE;

		if (w == 0)
			puts(YELLOW "🤝 It's a tie!" RESET);
		else
			printf(YELLOW "🏆 %s won!\n" RESET,
			       w == 1 ? "You" : "Dealer");
		NEWLINE;

		wait_for_enter();
	}

	free(dealer_hand);
	free(player_hand);

	return 0;
}

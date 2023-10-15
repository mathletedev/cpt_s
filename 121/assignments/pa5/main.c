/*
 * Name: Neal Wang
 * Due Date: 2023-10-25
 * Lecture: 02
 * Lab: 25
 * Assignment: PA 3
 * Description: An interactive game of Yahtzee
 */

#include "headers.h"

int main(void) {
	srand(time(NULL));

	// store all combination details in arrays for easy access
	char labels[] = "123456abcdefg";
	char *descriptions[] = {
	    "Sum of 1's      ", "Sum of 2's      ", "Sum of 3's      ",
	    "Sum of 4's      ", "Sum of 5's      ", "Sum of 6's      ",
	    "Three of a kind ", "Four of a kind  ", "Full house      ",
	    "Small straight  ", "Large straight  ", "YAHTZEE         ",
	    "Chance          "};

	while (1) {
		// main menu
		char input;
		int valid;
		do {
			write_menu();
			// validate user input
		} while (!read_option("123", &input));

		if (input == '1') {
			write_rules();
			continue;
		} else if (input == '3')
			break;

		// store scores of players in a 2-D array
		// a score of -1 means the combination has not been used yet
		int score_card[2][NUM_COMBINATIONS];
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < NUM_COMBINATIONS; ++j)
				score_card[i][j] = -1;
		}
		int curr_player = 0;

		// repeat NUM_COMBINATIONS times for 2 players (26 times total)
		for (int i = 0; i < 1 * 2; ++i) {
			clear();
			NEWLINE;

			printf(CYAN "👤 Player %d's turn\n" RESET,
			       curr_player + 1);
			NEWLINE;
			printf(GREEN " Press any key to roll dice..." RESET);
			wait_for_keypress();

			clear();
			NEWLINE;

			int num_rolls = 0;
			// store which dice the player wants to keep
			int keep[NUM_DICE + 1] = {0};
			while (num_rolls < 3) {
				++num_rolls;

				clear();
				NEWLINE;

				printf(CYAN "👤 Player %d's turn\n" RESET,
				       curr_player + 1);
				NEWLINE;

				printf(GREEN " %s roll...\n" RESET,
				       num_rolls == 1
					   ? "First"
					   : (num_rolls == 2 ? "Second"
							     : "Final"));
				NEWLINE;

				// IDs of each die
				printf(GREEN "ID [1] [2] [3] [4] [5]\n");

				// copied from PA 4
				int dice[NUM_DICE];
				time_t start = time(NULL);
				while (time(NULL) < start + ROLL_TIME) {
					int tmp_dice[NUM_DICE];
					roll_dice(tmp_dice);

					printf("🎲");
					for (int i = 0; i < NUM_DICE; ++i) {
						// only print blue colour for
						// non-kept dice
						if (keep[i + 1])
							printf(" [%d]",
							       dice[i]);
						else {
							printf(BLUE
							       " [%d]" RESET,
							       tmp_dice[i]);
							dice[i] = tmp_dice[i];
						}
					}
					printf("\r" RESET);
				}

				// print resulting dice
				printf("🎲");
				for (int i = 0; i < NUM_DICE; ++i) {
					if (!keep[i + 1])
						printf(BLUE);
					printf(" [%d]", dice[i]);
					printf(RESET);
				}
				printf("\n" RESET);
				NEWLINE;

				int sum = 0;
				// frequency array for single-number
				// combinations
				int frequency[7] = {0};
				for (int i = 0; i < NUM_DICE; ++i) {
					sum += dice[i];
					++frequency[dice[i]];
				}

				int three, four, full, small, large, yahtzee;
				three = four = full = small = large = yahtzee =
				    0;

				// full house pair
				int has_pair = 0;
				// x-of-a-kind combinations
				for (int i = 1; i < 7; ++i) {
					if (frequency[i] == 2)
						has_pair = 1;
					if (frequency[i] >= 3)
						three = sum;
					if (frequency[i] >= 4)
						four = sum;
					if (frequency[i] == 5)
						yahtzee = 50;
				}
				if (has_pair && three != 0)
					full = 25;

				// straights
				int curr_straight = 0, longest_straight = 0;
				for (int i = 1; i <= 6; ++i) {
					if (frequency[i] > 0) {
						++curr_straight;
						if (curr_straight >
						    longest_straight)
							longest_straight =
							    curr_straight;
					} else
						curr_straight = 0;
				}
				if (longest_straight >= 4) {
					small = 30;
					if (longest_straight == 5)
						large = 40;
				}

				int points[] = {frequency[1],
						frequency[2] * 2,
						frequency[3] * 3,
						frequency[4] * 4,
						frequency[5] * 5,
						frequency[6] * 6,
						three,
						four,
						full,
						small,
						large,
						yahtzee,
						sum};

				printf(GREEN
				       " Here are your combinations:\n" RESET);
				NEWLINE;
				// iterate over combination data and write each
				// one
				for (int i = 0; i < NUM_COMBINATIONS; ++i) {
					// don't display combination if already
					// used
					if (score_card[curr_player][i] != -1)
						continue;

					write_combination(labels[i],
							  descriptions[i],
							  points[i]);
				}
				NEWLINE;

				if (num_rolls < 3) {
					valid = -1;
					do {
						if (valid != -1) {
							NEWLINE;
							warn_invalid();
							NEWLINE;
						}
						write_question(
						    "Do you want to use this "
						    "roll "
						    "for a combination?");
						NEWLINE;
						write_option('y', "Yes");
						write_option('n', "No");
						NEWLINE;
						write_prompt(NULL);
						valid = 0;
					} while (!read_option("yn", &input));

					NEWLINE;
				} else
					input = 'y';

				// player wants to use a combination
				if (input == 'y') {
					valid = -1;
					do {
						if (valid != -1) {
							NEWLINE;
							warn_invalid();
							NEWLINE;
						}
						write_prompt(
						    "Select a combination");
						valid = 0;
					} while (
					    !read_option(labels, &input) ||
					    score_card[curr_player]
						      [combination_to_index(
							  input)] != -1);

					NEWLINE;

					// add points to score
					// note that this also uses up the
					// combination
					score_card
					    [curr_player]
					    [combination_to_index(input)] =
						points[combination_to_index(
						    input)];
					break;
				} else {
					// user wants to re-roll
					valid = -1;
					int num;
					do {
						if (valid != -1) {
							NEWLINE;
							warn_invalid();
							NEWLINE;
						}
						write_prompt(
						    "Enter the IDs of the "
						    "dice you want to keep "
						    "(without spaces)\n   "
						    "Enter a 0 if you do not "
						    "want to keep any dice");

						valid = 0;
						if (scanf("%d", &num) != 1)
							continue;

						valid = 1;
						if (num == 0)
							continue;

						int tmp_keep[NUM_DICE + 1] = {
						    0};
						// get individual digits of num
						// and keep them
						while (num > 0) {
							int digit = num % 10;
							if (digit == 0 ||
							    digit > NUM_DICE) {
								valid = 0;
								break;
							}
							tmp_keep[digit] = 1;
							num /= 10;
						}

						if (valid == 1) {
							for (int i = 0;
							     i < NUM_DICE + 1;
							     ++i)
								keep[i] =
								    tmp_keep[i];
						}
					} while (valid == 0);
				}
			}

			printf(CYAN " Player 1's score: " YELLOW "%d\n" RESET,
			       sum_score(score_card[0]));
			NEWLINE;
			printf(CYAN " Player 2's score: " YELLOW "%d\n" RESET,
			       sum_score(score_card[1]));
			NEWLINE;

			curr_player = !curr_player;

			printf(GREEN " Press any key to continue...");
			wait_for_keypress();
		}

		clear();
		NEWLINE;

		printf(GREEN " 🎮 Game over!\n" RESET);
		NEWLINE;

		printf(CYAN " Player 1's score: " YELLOW "%d\n" RESET,
		       sum_score(score_card[0]));
		NEWLINE;
		printf(CYAN " Player 2's score: " YELLOW "%d\n" RESET,
		       sum_score(score_card[1]));
		NEWLINE;

		printf(GREEN " Press any key to continue...");
		wait_for_keypress();
	}

	return 0;
}

/*
 * Name: Neal Wang
 * Due Date: 2023-10-25
 * Lecture: 02
 * Lab: 25
 * Assignment: PA 3
 * Description: An interactive game of Yahtzee
 */

#include "headers.h"
#include "io.h"

int main(void) {
	srand(time(NULL));

	int scores[2] = {0, 0};
	int curr_player = 0;

	while (1) {
		char input;
		int valid;
		do {
			write_menu();
		} while (!read_option("123", &input));

		if (input == '1') {
			write_rules();
			continue;
		} else if (input == '3')
			break;

		for (int i = 0; i < 13 * 2; ++i) {
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

				printf(GREEN "ID [1] [2] [3] [4] [5]\n");

				// copied from PA 4
				int dice[NUM_DICE];
				time_t start = time(NULL);
				while (time(NULL) < start + ROLL_TIME) {
					int tmp_dice[NUM_DICE];
					roll_dice(tmp_dice);

					printf("🎲");
					for (int i = 0; i < NUM_DICE; ++i) {
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
				int frequency[7] = {0};
				for (int i = 0; i < NUM_DICE; ++i) {
					sum += dice[i];
					++frequency[dice[i]];
				}

				int three, four, full, small, large, yahtzee;
				three = four = full = small = large = yahtzee =
				    0;
				for (int i = 1; i < 7; ++i) {
					if (frequency[i] >= 3)
						three = sum;
					if (frequency[i] >= 4)
						four = sum;
					if (frequency[i] == 5)
						yahtzee = 50;
				}

				printf(GREEN
				       " Here are your combinations:\n" RESET);
				NEWLINE;
				write_combination('1', "Sum of 1's      ",
						  frequency[1]);
				write_combination('2', "Sum of 2's      ",
						  frequency[2] * 2);
				write_combination('3', "Sum of 3's      ",
						  frequency[3] * 3);
				write_combination('4', "Sum of 4's      ",
						  frequency[4] * 4);
				write_combination('5', "Sum of 5's      ",
						  frequency[5] * 5);
				write_combination('6', "Sum of 6's      ",
						  frequency[6] * 6);
				write_combination('a', "Three-of-a-kind ",
						  three);
				write_combination('b', "Four-of-a-kind  ",
						  four);
				write_combination('c', "Full house      ",
						  full);
				write_combination('d', "Small straight  ",
						  small);
				write_combination('e', "Large straight  ",
						  large);
				write_combination('f', "Yahtzee         ",
						  yahtzee);
				write_combination('g', "Chance          ", sum);
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
				} else
					input = 'y';

				NEWLINE;

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
					} while (!read_option("123456abcdefg",
							      &input));

					NEWLINE;

					int points;
					switch (input) {
					case '1':
						points = frequency[1];
						break;
					case '2':
						points = frequency[2] * 2;
						break;
					case '3':
						points = frequency[3] * 3;
						break;
					case '4':
						points = frequency[4] * 4;
						break;
					case '5':
						points = frequency[5] * 5;
						break;
					case '6':
						points = frequency[6] * 6;
						break;
					case 'a':
						points = three;
						break;
					case 'b':
						points = four;
						break;
					case 'c':
						points = full;
						break;
					case 'd':
						points = small;
						break;
					case 'e':
						points = large;
						break;
					case 'f':
						points = yahtzee;
						break;
					case 'g':
						points = sum;
						break;
					}

					scores[curr_player] += points;
					break;
				} else {
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
						    "(without spaces)");

						valid = 0;
						if (scanf("%d", &num) != 1)
							continue;

						printf("%d\n", num);

						valid = 1;
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
			       scores[0]);
			NEWLINE;
			printf(CYAN " Player 2's score: " YELLOW "%d\n" RESET,
			       scores[1]);
			NEWLINE;

			curr_player = !curr_player;

			printf(GREEN " Press any key to continue...");
			wait_for_keypress();
		}
	}

	return 0;
}

/*
 * Name: Neal Wang
 * Due Date: 2023-10-25
 * Lecture: 02
 * Lab: 25
 * Assignment: PA 5
 * Description: Game utilities
 */

#include "utils.h"
#include "io.h"

/*
 * Writes YAHTZEE in ASCII text
 */
void yahtzee(void) {
	// https://fsymbols.com/generators/carty/
	printf(YELLOW);
	printf(
	    "  ██╗   ██╗ █████╗ ██╗  ██╗████████╗███████╗███████╗███████╗\n"
	    "  ╚██╗ ██╔╝██╔══██╗██║  ██║╚══██╔══╝╚════██║██╔════╝██╔════╝\n"
	    "   ╚████╔╝ ███████║███████║   ██║     ███╔═╝█████╗  █████╗  \n"
	    "    ╚██╔╝  ██╔══██║██╔══██║   ██║   ██╔══╝  ██╔══╝  ██╔══╝  \n"
	    "     ██║   ██║  ██║██║  ██║   ██║   ███████╗███████╗███████╗\n"
	    "     ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚══════╝╚══════╝╚══════╝\n");
	printf(RESET);
}

/*
 * Writes the game menu
 */
void write_menu(void) {
	clear();
	NEWLINE;

	yahtzee();
	NEWLINE;

	write_option('1', "Print game rules");
	write_option('2', "Start a game of Yahtzee");
	write_option('3', "Exit");
	NEWLINE;

	write_prompt(NULL);
}

/*
 * Writes the game rules
 */
void write_rules(void) {
	clear();
	NEWLINE;

	yahtzee();
	NEWLINE;

	printf(YELLOW);
	printf(
	    "⭐ The scorecard used for Yahtzee is composed of two sections,\n"
	    "   an upper section and a lower section.\n"
	    "⭐ A total of thirteen boxes or thirteen scoring combinations\n"
	    "   are divided amongst the sections.\n"
	    "⭐ The upper section consists of boxes that are scored by summing\n"
	    "   the value of the dice matching the faces of the box.\n"
	    "⭐ If a player rolls four 3's, then the score placed in the 3's\n"
	    "   box is the sum of the dice, which is 12.\n"
	    "⭐ Once a player has chosen to score a box, it may not be changed\n"
	    "   and the combination is no longer in play for future rounds.\n"
	    "⭐ If the sum of the scores in the upper section is greater than\n"
	    "   or equal to 63, then 35 more points are added to the player's\n"
	    "   overall score as a bonus.\n"
	    "⭐ The lower section contains a number of poker-like\n"
	    "   combinations.\n");
	printf(RESET);
	NEWLINE;

	printf(GREEN " Press any key to continue..." RESET);
	wait_for_keypress();
}

/*
 * Rolls NUM_DICE dice
 *
 * Parameters:
 * - int *dice: Dice array
 *
 * Pre-conditions:
 * - srand() has been called
 * - dice is an integer array with NUM_DICE elements
 *
 * Post-conditions: dice will be filled with NUM_DICE random integers between 1
 * and 6
 */
void roll_dice(int *dice) {
	for (int i = 0; i < NUM_DICE; ++i)
		dice[i] = rand() % 6 + 1;
}

/*
 * Converts a combination input to an index from 0-12
 *
 * Parameters:
 * - char combination: User-selected combination
 *
 * Pre-conditions: combination is one of "123456abcdefg"
 *
 * Returns an index from 0-12
 */
int combination_to_index(char combination) {
	// ASCII codes from https://www.asciitable.com
	if (combination < 'a')
		return combination - '1';
	// shift index by 6
	return combination - 'a' + 6;
}

/*
 * Calculates a player's score
 *
 * Parameters:
 * - int *arr: Scores of the player
 *
 * Returns the sum of the elements of arr, excluding -1s
 */
int sum_score(int *arr) {
	int sum = 0;
	for (int i = 0; i < NUM_COMBINATIONS; ++i) {
		if (arr[i] != -1)
			sum += arr[i];
		// if upper section sums to more than 63,
		// add a bonus 35 points
		if (i == 5 && sum >= 63)
			sum += 35;
	}
	return sum;
}

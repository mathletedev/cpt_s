/*
 * Name: Neal Wang
 * Date: 2023-10-07
 * Lecture: 02
 * Lab: 25
 * Assignment: PA 3
 * Description: Utility functions for the game
 */

#include "headers.h"

/*
 * Prints a new line
 */
void newline() { printf("\n"); }

/*
 * Formats a prompt, then prints it
 *
 * Parameters:
 * - char *details: Information to display to the user
 */
void prompt(char *details) {
	printf("❔ " MAGENTA "%s:" RESET "\n   > ", details);
}

/*
 * Prints the start of a warning
 */
void warn_begin() { printf("🚨 " RED); }

/*
 * Prints the end of a warning
 *
 * Pre-conditions: warn_begin() has been called
 */
void warn_end() { printf(RESET "\n\n"); }

/*
 * Returns a random warning message
 *
 * Post-conditions: Returns a string chosen at random
 */
char *warn_message() {
	// select a random message
	int random = rand() % 4;
	switch (random) {
	case 0:
		return "Whoa, buddy!";
	case 1:
		return "Chill out!";
	case 2:
		return "Hold your horses!";
	default:
		return "Calm down!";
	}
}

/*
 * Prints whether or not the user won (with colour)
 *
 * Parameters:
 * - int result: the result of the roll
 *
 * Pre-conditions: result is not -1
 */
void display_result(int result) {
	if (result == 1)
		printf(CYAN " Yon won!\n");
	else
		printf(RED " The house won...\n");
	newline();
}

/*
 * Prints the user's current balance (with colour)
 *
 * Parameters:
 * - double bank_balance: the user's current balance
 */
void display_balance(double bank_balance) {
	printf("💰 ");

	if (bank_balance > 0)
		printf(YELLOW);
	// print red text if user is in crippling debt
	else
		printf(RED);

	printf("Your balance is $%.2lf\n", bank_balance);
	newline();
}

/*
 * Prompts the user for either 'y' or 'n'
 *
 * Pre-conditions: The user entered a character
 *
 * Post-conditions: Returns the user's input
 */
char get_yes_no() {
	char data;

	prompt("Do you wish to continue playing? y/n");
	scanf(" %c", &data);
	newline();

	return data;
}

/*
 * Checks if a character is 'y' or 'n'
 *
 * Parameters:
 * - char input: The return value of get_yes_no()
 *
 * Pre-conditions: get_yes_no() has been called
 *
 * Post-conditions: Returns 1 if the character is 'y' or 'n', 0 otherwise
 */
int check_yes_no(char input) { return input == 'y' || input == 'n'; }

/*
 * Prints the rules of craps
 *
 * Pre-conditions: The game has not started
 */
void print_game_rules() {
	newline();
	printf(RED " --------" YELLOW "--------" GREEN "--------" CYAN
		   "--------" BLUE "--------" MAGENTA "--------" RESET "\n");
	newline();

	// ASCII text
	// source:
	// https://patorjk.com/software/taag/#p=display&f=Big%20Money-ne&t=CRAPS
	// worked together with Charles for the ASCII
	printf(YELLOW);
	printf("  /$$$$$$  /$$$$$$$   /$$$$$$  /$$$$$$$   /$$$$$$ \n");
	printf(" /$$__  $$| $$__  $$ /$$__  $$| $$__  $$ /$$__  $$\n");
	printf("| $$  \\__/| $$  \\ $$| $$  \\ $$| $$  \\ $$| $$  \\__/\n");
	printf("| $$      | $$$$$$$/| $$$$$$$$| $$$$$$$/|  $$$$$$ \n");
	printf("| $$      | $$__  $$| $$__  $$| $$____/  \\____  $$\n");
	printf("| $$    $$| $$  \\ $$| $$  | $$| $$       /$$  \\ $$\n");
	printf("|  $$$$$$/| $$  | $$| $$  | $$| $$      |  $$$$$$/\n");
	printf(" \\______/ |__/  |__/|__/  |__/|__/       \\______/ \n");
	printf(RESET);
	newline();

	printf(RED " --------" YELLOW "--------" GREEN "--------" CYAN
		   "--------" BLUE "--------" MAGENTA "--------" RESET "\n");
	newline();

	printf(GREEN " Welcome to the game of craps! Here are the rules:" RESET
		     "\n");
	newline();

	// rules are copied from the assignment
	printf(YELLOW);
	printf("⭐ A player rolls two dice. Each die has six faces.\n");
	printf("⭐ These faces contain 1, 2, 3, 4, 5, and 6 spots.\n");
	printf("⭐ After the dice have come to rest, the sum of the\n");
	printf("   spots on the two upward faces is calculated.\n");
	printf("⭐ If the sum is 7 or 11 on the first throw,\n");
	printf("   the player wins.\n");
	printf("⭐ If the sum is 2, 3, or 12 on the first throw\n");
	printf("   (called \"craps\"), the player loses\n");
	printf("   (i.e. the \"house\" wins).\n");
	printf("⭐ If the sum is 4, 5, 6, 8, 9, or 10 on the first\n");
	printf("   throw, then the sum becomes the player's \"point\".\n");
	printf("⭐ To win, you must continue rolling the dice until\n");
	printf("   you \"make your point\".\n");
	printf("⭐ The player loses by rolling a 7 before making\n");
	printf("   the point.\n");
	printf(RESET);
	newline();

	printf(GREEN " Let's play some craps!" RESET "\n");
}

/*
 * Prompts the user for the user's balance
 *
 * Pre-conditions: The user entered a positive floating-point number
 *
 * Post-conditions: Returns the user's balance
 */
double get_bank_balance() {
	double data;

	prompt("Enter your starting balance");
	scanf("%lf", &data);
	newline();

	return data;
}

/*
 * Prompts the user for the user's desired wager
 *
 * Pre-conditions: The user entered a positive floating-point number
 *
 * Post-conditions: Returns the user's desired wager
 */
double get_wager_amount() {
	double data;

	prompt("Enter the amount you want to wager");
	scanf("%lf", &data);
	newline();

	return data;
}

/* Checks if the user's wager is possible given the user's balance
 *
 * Parameters:
 * - double wager: The user's wager
 * - double balance: The user's balance
 *
 * Pre-conditions: Wager and balance are positive floating-point numbers
 *
 * Post-conditions: Returns 1 if wager is less than or equal to balance, 0
 * otherwise
 */
int check_wager_amount(double wager, double balance) {
	return wager > 0 && wager <= balance;
}

/*
 * Rolls a dice
 *
 * Pre-conditions: srand() has been called
 *
 * Post-conditions: Returns a random integer between 1 and 6, inclusive
 */
int roll_die() { return rand() % 6 + 1; }

/* Calculates the sum of 2 dice
 *
 * Parameters:
 * - int die1_value: The number on die 1
 * - int die2_value: The number on die 2
 *
 * Pre-conditions: roll_die() has been called 2 times
 *
 * Post-conditions: Returns the sum of the values on die 1 and die 2
 */
int calculate_sum_dice(int die1_value, int die2_value) {
	return die1_value + die2_value;
}

/*
 * Determines the result of the initial roll
 *
 * Parameters:
 * - int sum_dice: The sum of the 2 dice
 *
 * Pre-conditions: Only 1 roll has been made
 *
 * Post-conditions: Returns 1 if the user won, 0 if the user lost, -1 otherwise
 */
int is_win_loss_or_point(int sum_dice) {
	// immediate win
	if (sum_dice == 7 || sum_dice == 11)
		return 1;
	// immediate loss
	if (sum_dice == 2 || sum_dice == 3 || sum_dice == 12)
		return 0;
	// continue rolling
	return -1;
}

/*
 * Determines the result of successive rolls
 *
 * Parameters:
 * - int sum_dice: The sum of 2 dice
 * - int point_value: The user's point
 *
 * Pre-conditions:
 * - More than 1 roll has been made
 * - is_win_loss_or_point() has been called
 * - The turn didn't end on the first roll
 * - The user has a point
 *
 * Post-conditions: Returns 1 if the user won, 0 if the user lost, -1 otherwise
 */
int is_point_loss_or_neither(int sum_dice, int point_value) {
	if (sum_dice == point_value)
		return 1;
	if (sum_dice == 7)
		return 0;
	return -1;
}

/*
 * Calculates the user's new bank balance
 *
 * Parameters:
 * - double bank_balance: The user's current balance
 * - double wager_amount: The user's wager
 * - int add_or_subtract: The result of a roll
 *
 * Pre-conditions: is_win_loss_or_point() or is_point_loss_or_neither() has been
 * called
 *
 * Post-conditions: Returns the user's new bank balance
 */
double adjust_bank_balance(double bank_balance, double wager_amount,
			   int add_or_subtract) {
	switch (add_or_subtract) {
	case 1:
		return bank_balance + wager_amount;
	case 0:
		return bank_balance - wager_amount;
	default:
		return bank_balance;
	}
}

/*
 * Prints a message that is relevant to the state of the game in hopes of
 * feeding the user's gambing addiction
 *
 * Parameters:
 * - int number_rolls: The number of turns the user has taken
 * - int win_loss_neither: The result of the previous roll
 * - double initial_bank_balance: The user's initial balance
 * - double current_bank_balance: The user's current balance
 *
 * Pre-conditions: The user has taken at least one turn
 */
void chatter_messages(int number_rolls, int win_loss_neither,
		      double initial_bank_balance,
		      double current_bank_balance) {
	printf("💬 " GREEN);

	if (number_rolls % 10 == 0)
		printf("You're on fire! You've rolled %d times!", number_rolls);
	else {
		if (win_loss_neither == 1) {
			printf("Awesome! Keep it up!");
		} else {
			if (current_bank_balance < initial_bank_balance)
				printf("You've lost $%.2lf... but you can make "
				       "that back on this next roll!",
				       initial_bank_balance -
					   current_bank_balance);
			else if (current_bank_balance > initial_bank_balance)
				printf("You've already made $%.2lf... why not "
				       "make some more?",
				       current_bank_balance -
					   initial_bank_balance);
			else
				printf("You'll win this next one. I'm sure of "
				       "it!");
		}
	}

	printf(RESET "\n");
	newline();
}

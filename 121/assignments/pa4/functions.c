#include "headers.h"

/*
 * ANSI colour codes for cool text
 * Source:
 * https://stackoverflow.com/questions/3219393/stdlib-and-colored-output-in-c
 */
#define ANSI_COLOUR_RED "\x1b[31m"
#define ANSI_COLOUR_GREEN "\x1b[32m"
#define ANSI_COLOUR_YELLOW "\x1b[33m"
#define ANSI_COLOUR_BLUE "\x1b[34m"
#define ANSI_COLOUR_MAGENTA "\x1b[35m"
#define ANSI_COLOUR_CYAN "\x1b[36m"
#define ANSI_COLOUR_RESET "\x1b[0m"

void prompt(char *details) { printf("💡 %s:\n   > ", details); }
void info(char *details) { printf("🚨 %s\n\n", details); }
void newline() { printf("\n"); }

void print_game_rules() {
	printf("  ⭐⭐⭐  ");
	printf(ANSI_COLOUR_BLUE "CRAPS!");
	printf(ANSI_COLOUR_RESET "  ⭐⭐⭐  \n");
}

double get_bank_balance() {
	double data;

	prompt("Enter bank balance");
	scanf("%lf", &data);
	newline();

	return data;
}

double get_wager_amount() {
	double data;

	prompt("Enter wager amount");
	scanf("%lf", &data);
	newline();

	return data;
}

int check_wager_amount(double wager, double balance) {
	return wager <= balance;
}

int roll_die(void) { return rand() % 6 + 1; }

int calculate_sum_dice(int die1_value, int die2_value) {
	return die1_value + die2_value;
}

int is_win_loss_or_point(int sum_dice) {
	if (sum_dice == 7 || sum_dice == 11)
		return 1;
	if (sum_dice == 2 || sum_dice == 3 || sum_dice == 12)
		return 0;
	return -1;
}

int is_point_loss_or_neither(int sum_dice, int point_value) {
	if (sum_dice == point_value)
		return 1;
	if (sum_dice == 7)
		return 0;
	return -1;
}

double adjust_bank_balance(double bank_balance, double wager_amount,
			   int add_or_subtract) {
	switch (add_or_subtract) {
	case 1:
		return bank_balance + wager_amount;
	case 2:
		return bank_balance - wager_amount;
	default:
		return bank_balance;
	}
}

void chatter_messages(int number_rolls, int win_loss_neither,
		      double initial_bank_balance,
		      double current_bank_balance) {}

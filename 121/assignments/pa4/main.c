#include "headers.h"

int main(void) {
	srand(time(NULL));

	print_game_rules();
	newline();

	double bank_balance = get_bank_balance();

	double wager_amount;
	int invalid_input = 0;
	do {
		if (invalid_input)
			info("Wager amount ($%.2lf) is greater than bank "
			     "balance ($%.2lf)");
		invalid_input = 1;

		wager_amount = get_wager_amount();
	} while (!check_wager_amount(wager_amount, bank_balance));

	int die1 = roll_die();
	int die2 = roll_die();

	return 0;
}

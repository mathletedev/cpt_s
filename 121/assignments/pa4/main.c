#include "headers.h"

int main(void) {
	srand(time(NULL));

	print_game_rules();
	newline();

	double curr_balance = get_bank_balance();
	// keep track of initial balance for later
	double initial_balance = curr_balance;

	int num_rolls = 0;

	// main game loop
	do {
		++num_rolls;

		double wager_amount;
		// keep track of whether or not user input is valid
		int input_valid = 1;
		do {
			// if not valid, warn the user
			if (!input_valid) {
				warn_begin();
				if (wager_amount < 0)
					printf("%s You can't wager a negative "
					       "amount!",
					       warn_message());
				else if (wager_amount == 0)
					printf("%s You can't wager $0.00!",
					       warn_message());
				else
					printf("%s You can't wager $%.2lf when "
					       "you've only got $%.2lf!",
					       warn_message(), wager_amount,
					       curr_balance);
				warn_end();
			}
			input_valid = 0;

			wager_amount = get_wager_amount();
			// validate user input
		} while (!check_wager_amount(wager_amount, curr_balance));

		printf(GREEN " Rolling dice..." RESET "\n");
		newline();

		int die1, die2;
		int result = -1, point = -1;
		do {
			// run loop for ROLL_TIME seconds to simulate rolling
			// dice
			// source:
			// https://www.geeksforgeeks.org/time-function-in-c
			time_t start = time(NULL);
			while (time(NULL) < start + ROLL_TIME) {
				// get 2 random rolls
				die1 = roll_die();
				die2 = roll_die();

				// "\r" moves the carriage to the start of the
				// line
				// source:
				// https://www.reddit.com/r/cpp_questions/comments/14ypjb6/how_do_i_replace_already_printed_text_in_the
				printf("🎲 %d %d\r", die1, die2);
			}

			int sum_dice = calculate_sum_dice(die1, die2);

			// initial roll
			if (point == -1)
				result = is_win_loss_or_point(sum_dice);
			else
				// successive roll
				result =
				    is_point_loss_or_neither(sum_dice, point);

			printf("🎲 ");
			// set colour depending on result
			// win = cyan, loss = red, point = regular
			switch (result) {
			case 1:
				printf(CYAN);
				break;
			case 0:
				printf(RED);
				break;
			default:
				if (point == -1)
					printf(BLUE);
				break;
			}
			// show result of roll
			printf("%d %d -> %d" RESET "\n", die1, die2,
			       die1 + die2);
			newline();

			if (result == -1 && point == -1) {
				// set point
				point = sum_dice;
				printf(BLUE " Your point is: %d" RESET "\n",
				       point);
				newline();
			}
			// keep rolling until win or loss
		} while (result == -1);

		display_result(result);

		// adjust bank balance using result
		curr_balance =
		    adjust_bank_balance(curr_balance, wager_amount, result);

		display_balance(curr_balance);

		// if user doesn't have any money left, stop playing
		if (curr_balance <= 0)
			break;

		chatter_messages(num_rolls, result, initial_balance,
				 curr_balance);

		// check if user wants to continue playing
		char yes_no;
		input_valid = 1;
		do {
			if (!input_valid) {
				warn_begin();
				printf("Enter either \"y\" or \"n\"");
				warn_end();
			}
			input_valid = 0;

			yes_no = get_yes_no();
		} while (!check_yes_no(yes_no));

		// if user entered no, stop playing
		if (yes_no == 'n')
			break;
		// loop infinitely until user stops playing
	} while (1);

	// display end results
	if (curr_balance > initial_balance)
		printf(CYAN "🎉 Congratulations! You've won $%.2lf! You now "
			    "have $%.2lf!" RESET "\n",
		       curr_balance - initial_balance, curr_balance);
	else if (curr_balance > 0)
		printf(YELLOW "🪙 You now have $%.2lf" RESET "\n",
		       curr_balance);
	else
		printf(RED "💣 You ran out of money..." RESET "\n");
	newline();

	printf(GREEN " Thanks for playing!\n");
	printf(RESET);
	newline();

	return 0;
}

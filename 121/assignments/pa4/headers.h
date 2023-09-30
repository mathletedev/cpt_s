#ifndef headers_h
#define headers_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ANSI colour codes for cool text
// https://stackoverflow.com/questions/3219393/stdlib-and-colored-output-in-c
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"

// constants
#define ROLL_TIME 1

// my functions
// comments and details are in functions.c
void newline(void);
void prompt(char *details);
void warn_begin(void);
void warn_end(void);
char *warn_message(void);
void display_result(int result);
void display_balance(double bank_balance);
char get_yes_no(void);
int check_yes_no(char input);

// PA functions
void print_game_rules(void);
double get_bank_balance(void);
double get_wager_amount(void);
int check_wager_amount(double wager, double balance);
int roll_die(void);
int calculate_sum_dice(int die1_value, int die2_value);
int is_win_loss_or_point(int sum_dice);
int is_point_loss_or_neither(int sum_dice, int point_value);
double adjust_bank_balance(double bank_balance, double wager_amount,
			   int add_or_subtract);
void chatter_messages(int number_rolls, int win_loss_neither,
		      double initial_bank_balance, double current_bank_balance);

#endif

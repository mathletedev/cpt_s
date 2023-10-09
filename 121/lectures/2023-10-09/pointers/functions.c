#include "headers.h"

int dispense_change(double cost, double payment, int *twenties_ptr,
		    int *tens_ptr, int *fives_ptr, int *ones_ptr,
		    int *quarters_ptr, int *dimes_ptr, int *nickels_ptr,
		    int *pennies_ptr) {
	int total = 0;
	double change = payment - cost;

	int pennies = (int)(change * 100);

	*twenties_ptr = pennies / 2000;
	pennies -= *twenties_ptr * 2000;
	total += *twenties_ptr;

	*tens_ptr = pennies / 1000;
	pennies -= *tens_ptr * 1000;
	total += *tens_ptr;

	*fives_ptr = pennies / 500;
	pennies -= *fives_ptr * 500;
	total += *fives_ptr;

	*ones_ptr = pennies / 100;
	pennies -= *ones_ptr * 100;
	total += *ones_ptr;

	*quarters_ptr = pennies / 25;
	pennies -= *quarters_ptr * 25;
	total += *quarters_ptr;

	*dimes_ptr = pennies / 10;
	pennies -= *dimes_ptr * 10;
	total += *dimes_ptr;

	*nickels_ptr = pennies / 5;
	pennies -= *nickels_ptr * 5;
	total += *nickels_ptr;

	*pennies_ptr = pennies;
	total += *pennies_ptr;

	return total;
}

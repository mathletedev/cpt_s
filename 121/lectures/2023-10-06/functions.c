#include "headers.h"

int dispense_change(double cost, double payment, int *twenties_ptr,
		    int *tens_ptr, int *fives_ptr, int *ones_ptr,
		    int *quarters_ptr, int *dimes_ptr, int *nickels_ptr,
		    int *pennies_ptr) {
	int total = 0;
	double change = payment - cost;

	double pennies = (int)(change * 100);

	*twenties_ptr = pennies / 2000;
	pennies -= (*twenties_ptr) * 2000;

	return total;
}

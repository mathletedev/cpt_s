#include "headers.h"

int main(void) {
	int twenties = 0, tens = 0, fives = 0, ones = 0, quarters = 0,
	    dimes = 0, nickels = 0, pennies = 0;

	int total =
	    dispense_change(7.37, 50.00, &twenties, &tens, &fives, &ones,
			    &quarters, &dimes, &nickels, &pennies);

	printf("Twenties: %d\n", twenties);

	return 0;
}

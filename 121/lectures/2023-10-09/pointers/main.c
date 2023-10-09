#include "headers.h"

int main(void) {
	double cost, payment;
	printf("Enter cost: ");
	scanf("%lf", &cost);
	printf("Enter payment: ");
	scanf("%lf", &payment);

	printf("\n");

	int twenties = 0, tens = 0, fives = 0, ones = 0, quarters = 0,
	    dimes = 0, nickels = 0, pennies = 0;

	int total =
	    dispense_change(cost, payment, &twenties, &tens, &fives, &ones,
			    &quarters, &dimes, &nickels, &pennies);

	printf("Twenties: %d\n", twenties);
	printf("Tens: %d\n", tens);
	printf("Fives: %d\n", fives);
	printf("Ones: %d\n", ones);
	printf("Quarters: %d\n", quarters);
	printf("Dimes: %d\n", dimes);
	printf("Nickels: %d\n", nickels);
	printf("Pennies: %d\n", pennies);
	printf("Total: %d\n", total);

	return 0;
}

#include "headers.h"

void charges(double hours, double *total_cost, double *average_cost) {
	*total_cost = 7.99;
	if (hours > 10)
		*total_cost += 1.99 * (ceil(hours) - 10);

	*average_cost = *total_cost / hours;
}

double round_money(double money) { return floor(money * 100) / 100; }

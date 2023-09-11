#include "headers.h"

int main(void) {
	double h, s, theta;

	h = get_data("building height (feet)");
	theta = get_data("angle to Sun (degrees)");

	s = calc_shadow(h, theta);

	display(h, theta, s);

	return 0;
}

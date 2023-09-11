#include "headers.h"

void display(double h, double theta, double s) {
	printf("When the Sun is at an angle %g (degrees), ", theta);
	printf("and a building is a height %g (feet), ", h);
	printf("then the shadow is length %g (feet).\n", s);
}

double get_data(char *prompt) {
	double x;

	printf("Enter %s: ", prompt);
	scanf("%lf", &x);

	return x;
}

double calc_shadow(double h, double theta) {
	return h / tan(theta * M_PI / 180);
}

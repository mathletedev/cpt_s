#include "funcs.h"

// slope = change in y over change in x
double calculate_slope(Point a, Point b) { return (a.y - b.y) / (a.x - b.x); }

Point calculate_midpoint(Point a, Point b) {
	Point res;
	// average x values
	res.x = (a.x + b.x) / 2;
	// average y values
	res.y = (a.y + b.y) / 2;

	// midpoint is average of points
	return res;
}

// reciprocal = - (1 / x)
double calculate_reciprocal_slope(double slope) { return -1 / slope; }

// y-int = y_mid - m * x_mid
double calculate_y_intercept(Point midpoint, double slope) {
	return midpoint.y - slope * midpoint.x;
}

// bmi = weight / (height (in))^2 * 703
double calculate_bmi(double height, double weight) {
	return (weight / (height * 12 * height * 12)) * 703;
}

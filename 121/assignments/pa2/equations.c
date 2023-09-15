#include "equations.h"

double calculate_newtons_2nd_law(double mass, double acceleration) {
	return mass * acceleration;
}

double calculate_volume_cylinder(double radius, double height) {
	return M_PI * radius * radius * height;
}

char perform_character_encoding(char plaintext_character) {
	return (plaintext_character - 'a') + 'A';
}

double calculate_gravity(double mass1, double mass2, double distance) {
	return G * mass1 * mass2 / (distance * distance);
}

double calculate_resistive_divider(double r1, double r2, double vin) {
	return r2 / (r1 + r2) * vin;
}

double calculate_distance(double x1, double y1, double x2, double y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double calculate_general_equation(double x, double z, int a) {
	return ((double)73 / 12) - x * z + (a / (a % 2));
}

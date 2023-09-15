/*
 * Programmer: Neal Wang
 * Class: CptS 121, Fall 2023; Lab Section 25
 * Programming Assignment: 2
 * Date: 2023-09-15
 * Description:
 *   1) Newton's Second Law
 *   2) Volume of a cylinder
 *   3) Character encoding
 *   4) Gravity
 *   5) Resistive divider
 *   6) Distance between two points
 *   7) General equation
 *
 *   This time, using the 4-file structure
 */

#include "headers.h"

void part(int num);

int main(void) {
	// separate parts
	part(1);

	double mass, acceleration;
	// prompt for input
	printf("Enter mass (double) and acceleration (double): ");
	// read input
	scanf("%lf%lf", &mass, &acceleration);

	// output formula and answer
	printf("force = mass * acceleration = %.2lf * %.2lf = %.2lf\n\n", mass,
	       acceleration, calculate_newtons_2nd_law(mass, acceleration));

	part(2);

	double radius, height;
	printf("Enter radius (double) and height (double): ");
	scanf("%lf%lf", &radius, &height);

	printf("volume_cylinder = PI * radius^2 * height = %.2lf * %.2lf^2 * "
	       "%.2lf = "
	       "%.2lf\n\n",
	       M_PI, radius, height, calculate_volume_cylinder(radius, height));

	part(3);

	// plaintext_character is a char
	char plaintext_character;
	printf("Enter plaintext_character (char): ");
	scanf(" %c", &plaintext_character);

	// encoded_character will be the uppercase of plaintext_character if
	// plaintext_character is lowercase
	printf("encoded_character = (plaintext_character - 'a') + 'A' = (%c - "
	       "'a') + 'A' = %c\n\n",
	       plaintext_character,
	       perform_character_encoding(plaintext_character));

	part(4);

	double mass1, mass2, distance;
	printf("Enter mass1 (double), mass2 (double), and distance (double): ");
	scanf("%lf%lf%lf", &mass1, &mass2, &distance);

	printf(
	    "force = G * mass1 * mass2 / distance^2 = %.2lf * %.2lf * %.2lf / "
	    "%.2lf^2 = %.2lf\n\n",
	    G, mass1, mass2, distance,
	    calculate_gravity(mass1, mass2, distance));

	part(5);

	double r1, r2, vin;
	printf("Enter r1 (double), r2 (double), and vin (double): ");
	scanf("%lf%lf%lf", &r1, &r2, &vin);

	// be careful with order of outputs
	printf("vout = r2 / (r1 + r2) * vin = %.2lf / (%.2lf + %.2lf) * %.2lf "
	       "= %.2lf\n\n",
	       r2, r1, r2, vin, calculate_resistive_divider(r1, r2, vin));

	part(6);

	double x1, y1, x2, y2;
	printf(
	    "Enter x1 (double), y1 (double), x2 (double), and y2 (double): ");
	scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);

	printf("distance = sqrt((x1 - x2)^2 + (y1 - y2)^2) = sqrt((%.2lf - "
	       "%.2lf)^2 + (%.2lf - %.2lf)^2) = %.2lf\n\n",
	       x1, x2, y1, y2, calculate_distance(x1, y1, x2, y2));

	part(7);

	double x, z;
	// a is an int
	int a;
	printf("Enter x (double), z (double), and a (int): ");
	scanf("%lf%lf%d", &x, &z, &a);

	printf("y = (73 / 12) - x * z + a / (a %% 2) = (73 / 12) - %.2lf * "
	       "%.2lf + "
	       "%d / (%d %% 2) = %.2lf\n\n",
	       x, z, a, a, calculate_general_equation(x, z, a));

	return 0;
}

void part(int num) { printf("<--- Part %d --->\n", num); }

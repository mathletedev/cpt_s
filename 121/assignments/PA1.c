/*
 * Programmer: Neal Wang
 * Class: CptS 121, Fall 2023; Lab Section 25
 * Programming Assignment: 1
 * Date: 2023-09-05
 * Description:
 *   1) Newton's Second Law
 *   2) Volume of a cylinder
 *   3) Character encoding
 *   4) Gravity
 *   5) Resistive divider
 *   6) Distance between two points
 *   7) General equation
 */

// constants
#define PI 3.14
#define G 6.67e-11

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
// sqrt() for distance equation
#include <math.h>

void part_1(void) {
	// separate parts
	printf("<--- Part 1 --->");

	double mass, acceleration;
	// prompt for mass and acceleration
	printf("Enter mass (double) and acceleration (double): ");
	// read mass and acceleration
	scanf("%lf%lf", &mass, &acceleration);

	printf("force = mass * acceleration = %lf * %lf = %lf\n\n", mass,
	       acceleration, mass * acceleration);
}

void part_2(void) {
	printf("<--- Part 2 --->");

	double radius, height;
	printf("Enter radius (double) and height (double): ");
	scanf("%lf%lf", &radius, &height);

	// use x * x instead of x^2
	printf("volume_cylinder = PI * radius^2 * height = %lf * %lf^2 * %lf = "
	       "%lf\n\n",
	       PI, radius, height, PI * radius * radius * height);
}

void part_3(void) {
	printf("<--- Part 3 --->");

	// plaintext_character is a char
	char plaintext_character;
	printf("Enter plaintext_character (char): ");
	scanf("%c", &plaintext_character);

	// encoded_character will be the uppercase of plaintext_character if
	// plaintext_character is lowercase
	printf("encoded_character = (plaintext_character - 'a') + 'A' = (%c - "
	       "'a') + 'A' = %c\n\n",
	       plaintext_character, (plaintext_character - 'a') + 'A');
}

void part_4(void) {
	printf("<--- Part 4 --->");

	double mass1, mass2, distance;
	printf("Enter mass1 (double), mass2 (double), and distance (double): ");
	scanf("%lf%lf%lf", &mass1, &mass2, &distance);

	printf("force = G * mass1 * mass2 / distance^2 = %lf * %lf * %lf / "
	       "%lf^2 = %lf\n\n",
	       G, mass1, mass2, distance,
	       G * mass1 * mass2 / (distance * distance));
}

void part_5(void) {
	printf("<--- Part 5 --->");

	double r1, r2, vin;
	printf("Enter r1 (double), r2 (double), and vin (double): ");
	scanf("%lf%lf%lf", &r1, &r2, &vin);

	// be careful with order of outputs
	printf(
	    "vout = r2 / (r1 + r2) * vin = %lf / (%lf + %lf) * %lf = %lf\n\n",
	    r2, r1, r2, vin, r2 / (r1 + r2) * vin);
}

void part_6(void) {
	printf("<--- Part 6 --->");

	double x1, x2, y1, y2;
	printf(
	    "Enter x1 (double), x2 (double), y1 (double), and y2 (double): ");
	scanf("%lf%lf%lf%lf", &x1, &x2, &y1, &y2);

	// use sqrt() from <math.h>
	printf("distance = sqrt((x1 - x2)^2 + (y1 - y2)^2) = sqrt((%lf - "
	       "%lf)^2 + (%lf - %lf)^2) = %lf\n\n",
	       x1, x2, y1, y2,
	       sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
}

void part_7(void) {
	printf("<--- Part 7 --->");

	double x, z;
	// a is an int
	int a;
	printf("Enter x (double), z (double), and a (int): ");
	scanf("%lf%lf%d", &x, &z, &a);

	// cast 73 to double for precision
	printf("y = (73 / 12) - x * z + a / (a %% 2) = (73 / 12) - %lf * %lf + "
	       "%d / (%d %% 2) = %lf\n\n",
	       x, z, a, a, ((double)73 / 12) - x * z + (a / (a % 2)));
}

int main(void) {
	part_1();
	part_2();
	part_3();
	part_4();
	part_5();
	part_6();
	part_7();

	return 0;
}

/*
 * Programmer: Neal Wang
 * Class: CptS 121, Fall 2023; Lab Section 25
 * Programming Assignment: Lab1Task2
 * Date: 2023-08-31
 * Description:
 *   A) Some arithmetic operations
 *   B) Ohm's Law
 *   C) Joule's Law
 *   D) Third-order polynomial equation
 *   E) Circumference of circle
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void part_a(void) {
	printf("<- Task A ->\n");

	int number1_int = 0, number2_int = 0;
	double number1_float = 0.0, number2_float = 0.0;

	printf("Enter two integer values: ");
	scanf("%d%d", &number1_int, &number2_int);

	printf("Enter two floating-point values: ");
	scanf("%lf%lf", &number1_float, &number2_float);

	printf("int1 + int2:     %d\n", number1_int + number2_int);
	printf("float2 - float1: %f\n", number2_float - number1_float);
	printf("int1 * float1:   %d\n", (int)(number1_int * number1_float));
	// integer division - result is truncated
	// no difference between printf()s because of when it is cast
	printf("int1 / int2:     %d\n", number1_int / number2_int);
	printf("int1 / int2:     %f\n", (float)(number1_int / number2_int));
	// this has more precision
	printf("int1 / float2:   %d\n", (int)(number1_int / number2_float));
	printf("int1 / float2:   %f\n", number1_int / number2_float);
	printf("int1 / int2:     %f\n", (float)number1_int / number2_int);
	// float mod won't compile, so cast to int
	printf("float1 %% float2: %d\n",
	       (int)number1_float % (int)number2_float);
	printf("int1 even/odd:   %d\n", number1_int % 2);
	printf("int2 even/odd:   %d\n", number2_int % 2);
}

void part_b(void) {
	printf("<- Task B ->\n");

	int I, R;

	printf("Enter I and R: ");
	scanf("%d%d", &I, &R);

	// V = IR
	printf("Voltage (V): %d\n", I * R);
}

void part_c(void) {
	printf("<- Task C ->\n");

	int V, R;

	printf("Enter V and R: ");
	scanf("%d%d", &V, &R);

	// loss of precision due to integer division
	// P = V^2 / R
	printf("Power (P): %d\n", V * V / R);
}

void part_d(void) {
	printf("<- Task D ->\n");

	int x, a, b, c, d;
	printf("Enter x, a, b, c, and d: ");
	scanf("%d%d%d%d%d", &x, &a, &b, &c, &d);

	// 1/4 will be 0, so use 0.25 instead
	// loss of precision due to final int cast
	// y = 3 * ax^3 + (1/4) * bx^2 + 10 * cx + (-5) * d
	printf("y: %d\n", (int)(3 * a * x * x * x + 0.25 * b * x * x +
				10 * c * x + -5 * d));
}

void part_e(void) {
	printf("<- Task E ->\n");

	float radius;
	printf("Enter radius: ");
	scanf("%f", &radius);

	float PI = 3.14;
	// 2 * PI * radius
	printf("Circumference: %f\n", 2 * PI * radius);
}

int main(void) {
	part_a();
	printf("\n");
	part_b();
	printf("\n");
	part_c();
	printf("\n");
	part_d();
	printf("\n");
	part_e();

	return 0;
}

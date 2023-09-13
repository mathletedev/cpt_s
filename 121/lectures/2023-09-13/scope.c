#include <math.h>
#include <stdio.h>

double x = 0; // global variable

void cube_it(double y);

int main(void) {
	double base = 0, x = 0;

	printf("Enter base: ");
	scanf("%lf", &base);
	cube_it(base);
	printf("%g^3 = %g\n", base, x);

	return 0;
}

void cube_it(double y) { x = pow(y, 3); }

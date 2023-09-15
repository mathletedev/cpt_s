#include "funcs.h"
#include "headers.h"

int main(void) {
	// task 1: find equation of perpendicular bisector of a line segment
	printf("<--- Task 1 --->\n");

	Point point1, point2;
	printf("Enter double-precision x and y coordinates for point 1: ");
	scanf("%lf%lf", &point1.x, &point1.y);
	printf("Enter double-precision x and y coordinates for point 2: ");
	scanf("%lf%lf", &point2.x, &point2.y);

	double slope = calculate_slope(point1, point2);
	printf("Slope: %lf\n", slope);
	Point midpoint = calculate_midpoint(point1, point2);
	printf("Midpoint: (%lf, %lf)\n", midpoint.x, midpoint.y);
	double rec_slope = calculate_reciprocal_slope(slope);
	printf("Reciprocal of slope: %lf\n", rec_slope);
	double y_int = calculate_y_intercept(midpoint, rec_slope);
	printf("Y-intercept: %lf\n", y_int);

	printf("Original points: (%lf, %lf) and (%lf, %lf)\n", point1.x,
	       point1.y, point2.x, point2.y);
	printf("Equation of line: y = %lfx + %lf\n\n", rec_slope, y_int);

	// task 2: bmi calculator
	printf("<--- Task 2 --->\n");

	double height, weight;
	printf("Enter height (ft) and weight (lbs): ");
	scanf("%lf%lf", &height, &weight);

	double bmi = calculate_bmi(height, weight);
	printf("BMI: %lf\n", bmi);

	return 0;
}

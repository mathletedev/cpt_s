#include <stdio.h>

double get_weight(void);
double get_height(void);
double convert_feet_to_inches(double height_in_feet);
double calculate_bmi(double weight_in_pounds, double height_in_feet);
void display_bmi(double bmi) { printf("BMI: %.1lf\n", bmi); }

int main(void) {
	double weight_in_pounds = get_weight();
	double height_in_feet = get_height();

	display_bmi(calculate_bmi(weight_in_pounds, height_in_feet));

	return 0;
}

double get_weight(void) {
	double weight;

	printf("Enter weight in pounds: ");
	scanf("%lf", &weight);

	return weight;
}

double get_height(void) {
	double height;

	printf("Enter height in feet: ");
	scanf("%lf", &height);

	return height;
}

double convert_feet_to_inches(double height_in_feet) {
	return height_in_feet * 12;
}

double calculate_bmi(double weight_in_pounds, double height_in_feet) {
	double height_in_inches = convert_feet_to_inches(height_in_feet);

	return (weight_in_pounds / (height_in_inches * height_in_inches)) * 703;
}

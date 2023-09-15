#include "functions.h"

double read(char *prompt) {
	double data;

	printf("Enter score for %s: ", prompt);
	scanf("%lf", &data);

	return data;
}

double average(double num1, double num2) { return (num1 + num2) / 2; }

void display_average(char *type, double avg) {
	printf("Average %s score: %g\n", type, avg);
}

double weighted_average(double exam_avg, double lab_avg, double project_avg) {
	return exam_avg * 2 * 0.3 + lab_avg * 2 * 0.05 + project_avg * 2 * 0.15;
}

void display_weighted_average(double weighted_avg) {
	printf("Weighted average: %g\n", weighted_avg);
}

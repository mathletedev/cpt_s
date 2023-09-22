#include "functions.h"

double read(char *prompt) {
	double data;

	printf("Enter %s: ", prompt);
	scanf("%lf", &data);

	return data;
}

double calculate_time(double distance, double velocity, double theta) {
	return distance / (velocity * cos(theta));
}

double calculate_height(double velocity, double theta, double time) {
	return velocity * sin(theta) * time - (G * time * time / 2);
}

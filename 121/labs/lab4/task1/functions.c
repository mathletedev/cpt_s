#include "headers.h"

double read_double(FILE *infile) {
	double data;
	fscanf(infile, "%lf", &data);

	return data;
}

char read_char(FILE *infile) {
	char data;
	fscanf(infile, " %c", &data);

	return data;
}

double calculate_bmr(double age, char gender, double weight, double height) {
	double bmr = -1;

	switch (gender) {
	case 'W':
		bmr = 655 + (4.35 * weight) + (4.7 * height) - (4.7 * age);
		break;
	case 'M':
		bmr = 66 + (6.23 * weight) + (12.7 * height) - (6.8 * age);
		break;
	}

	return bmr;
}

double calculate_multiplier(int level) {
	double multiplier = -1;

	switch (level) {
	case 1:
		multiplier = 1.2;
		break;
	case 2:
		multiplier = 1.375;
		break;
	case 3:
		multiplier = 1.55;
		break;
	case 4:
		multiplier = 1.725;
		break;
	case 5:
		multiplier = 1.9;
		break;
	}

	return multiplier;
}

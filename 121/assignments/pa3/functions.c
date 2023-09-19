#include "headers.h"

// read a double-precision number from infile
double read_double(FILE *infile) {
	double data;
	fscanf(infile, "%lf", &data);

	return data;
}

// read an integer from infile
int read_integer(FILE *infile) {
	int data;
	fscanf(infile, "%d", &data);

	return data;
}

// calculates the sum of number1 ... number5
double calculate_sum(double number1, double number2, double number3,
		     double number4, double number5) {
	return number1 + number2 + number3 + number4 + number5;
}

// calculates the mean through sum / number
double calculate_mean(double sum, int number) { return sum / number; }

// calculates the deviation through number - mean
double calculate_deviation(double number, double mean) { return number - mean; }

// calculates the variance by taking the mean of all squared deviations
// use calculate_mean() and calculate_sum() from above
double calculate_variance(double deviation1, double deviation2,
			  double deviation3, double deviation4,
			  double deviation5, int number) {
	return calculate_mean(
	    calculate_sum(deviation1 * deviation1, deviation2 * deviation2,
			  deviation3 * deviation3, deviation4 * deviation4,
			  deviation5 * deviation5),
	    5);
}

// calculates the standard deviation through sqrt(variance)
double calculate_standard_deviation(double variance) { return sqrt(variance); }

// finds the maximum number in number1 ... number5
// keep a rolling max and take the next number if larger
double find_max(double number1, double number2, double number3, double number4,
		double number5) {
	double curr_max = number1;

	if (number2 > curr_max)
		curr_max = number2;
	if (number3 > curr_max)
		curr_max = number3;
	if (number4 > curr_max)
		curr_max = number4;
	if (number5 > curr_max)
		curr_max = number5;

	return curr_max;
}

// finds the minimum number in number1 ... number5
// keep a rolling min and take the next number if smaller
double find_min(double number1, double number2, double number3, double number4,
		double number5) {
	double curr_min = number1;

	if (number2 < curr_min)
		curr_min = number2;
	if (number3 < curr_min)
		curr_min = number3;
	if (number4 < curr_min)
		curr_min = number4;
	if (number5 < curr_min)
		curr_min = number5;

	return curr_min;
}

// writes a double-precision number to outfile
void print_double(FILE *outfile, double number) {
	fprintf(outfile, "%.2lf\n", number);
}

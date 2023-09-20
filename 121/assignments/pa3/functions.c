#include "headers.h"

/*
 * Description: Reads a double-precision number from infile
 * Date: 2023-09-19
 * Author: Neal Wang
 * Pre-conditions: infile is not NULL and is readable, another double exists
 * Post-conditions:
 * Returns: Next double in infile
 * See also: read_integer()
 */
double read_double(FILE *infile) {
	double data;
	fscanf(infile, "%lf", &data);

	return data;
}

/*
 * Description: Reads an integer from infile
 * Date: 2023-09-19
 * Author: Neal Wang
 * Pre-conditions: infile is not NULL and is readable, another integer exists
 * Post-conditions:
 * Returns: Next integer in infile
 * See also: read_double()
 */
int read_integer(FILE *infile) {
	int data;
	fscanf(infile, "%d", &data);

	return data;
}

/*
 * Description: Sums 5 numbers
 * Date: 2023-09-19
 * Author: Neal Wang
 * Pre-conditions: 5 doubles are provided, sum won't overflow
 * Post-conditions:
 * Returns: Sum of number1 ... number5
 * See also:
 */
double calculate_sum(double number1, double number2, double number3,
		     double number4, double number5) {
	return number1 + number2 + number3 + number4 + number5;
}

/*
 * Description: Calculates the mean through sum / number
 * Date: 2023-09-19
 * Author: Neal Wang
 * Pre-conditions: sum is a double, number is an int
 * Post-conditions:
 * Returns: Mean of numbers
 * See also:
 */
double calculate_mean(double sum, int number) { return sum / number; }

/*
 * Description: Calculates the deviation through number - mean
 * Date: 2023-09-19
 * Author: Neal Wang
 * Pre-conditions: number and mean are doubles
 * Post-conditions:
 * Returns: Difference between number and mean
 * See also:
 */
double calculate_deviation(double number, double mean) { return number - mean; }

/*
 * Description: Calculates the variance of 5 numbers by taking the mean of all
 *   squared deviations
 * Date: 2023-09-19
 * Author: Neal Wang
 * Pre-conditions: 5 doubles are provided, number is an int
 * Post-conditions:
 * Returns: Variance of 5 numbers
 * See also: calculate_mean(), calculate_sum()
 */
double calculate_variance(double deviation1, double deviation2,
			  double deviation3, double deviation4,
			  double deviation5, int number) {
	return calculate_mean(
	    calculate_sum(deviation1 * deviation1, deviation2 * deviation2,
			  deviation3 * deviation3, deviation4 * deviation4,
			  deviation5 * deviation5),
	    5);
}

/*
 * Description: Calculates the standard deviation by taking the square root
 *   of variance
 * Date: 2023-09-19
 * Author: Neal Wang
 * Pre-conditions: variance is a non-negative double, <math.h> is included
 * Post-conditions:
 * Returns: Standard deviation of variance
 * See also:
 */
double calculate_standard_deviation(double variance) { return sqrt(variance); }

/*
 * Description: Finds the maximum number in number1 ... number5
 *   Keep a rolling max and take the next number if larger
 * Date: 2023-09-19
 * Author: Neal Wang
 * Pre-conditions: 5 doubles are provided
 * Post-conditions:
 * Returns: Maximum number in number1 ... number5
 * See also: find_min()
 */
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

/*
 * Description: Finds the minimum number in number1 ... number5
 *   Keep a rolling min and take the next number if smaller
 * Date: 2023-09-19
 * Author: Neal Wang
 * Pre-conditions: 5 doubles are provided
 * Post-conditions:
 * Returns: Minumum number in number1 ... number5
 * See also: find_max()
 */
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

/*
 * Description: Writes a double to outfile
 * Date: 2023-09-19
 * Author: Neal Wang
 * Pre-conditions: outfile is not NULL and is readable, number is a double
 * Post-conditions: number is written to outfile to the hundredths place
 * Returns:
 * See also:
 */
void print_double(FILE *outfile, double number) {
	fprintf(outfile, "%.2lf\n", number);
}

#include "headers.h"

int main(void) {
	// open input.dat file for reading
	FILE *infile = fopen("input.dat", "r");
	// open output.dat file for writing
	FILE *outfile = fopen("output.dat", "w");

	// use read_integer() and read_double() to read each student's data
	int id1 = read_integer(infile);
	double gpa1 = read_double(infile);
	int class1 = read_integer(infile);
	double age1 = read_double(infile);

	int id2 = read_integer(infile);
	double gpa2 = read_double(infile);
	int class2 = read_integer(infile);
	double age2 = read_double(infile);

	int id3 = read_integer(infile);
	double gpa3 = read_double(infile);
	int class3 = read_integer(infile);
	double age3 = read_double(infile);

	int id4 = read_integer(infile);
	double gpa4 = read_double(infile);
	int class4 = read_integer(infile);
	double age4 = read_double(infile);

	int id5 = read_integer(infile);
	double gpa5 = read_double(infile);
	int class5 = read_integer(infile);
	double age5 = read_double(infile);

	// calculate sums of gpas, classes, and ages
	double gpa_sum = calculate_sum(gpa1, gpa2, gpa3, gpa4, gpa5);
	double class_sum =
	    calculate_sum(class1, class2, class3, class4, class5);
	double age_sum = calculate_sum(age1, age2, age3, age4, age5);

	// calculate means of gpas, classes, and ages
	double gpa_mean = calculate_mean(gpa_sum, 5);
	double class_mean = calculate_mean(class_sum, 5);
	double age_mean = calculate_mean(age_sum, 5);

	// write means to file
	print_double(outfile, gpa_mean);
	print_double(outfile, class_mean);
	print_double(outfile, age_mean);

	// calculate deviation from each student's gpa to gpa_mean
	double deviation1 = calculate_deviation(gpa1, gpa_mean);
	double deviation2 = calculate_deviation(gpa2, gpa_mean);
	double deviation3 = calculate_deviation(gpa3, gpa_mean);
	double deviation4 = calculate_deviation(gpa4, gpa_mean);
	double deviation5 = calculate_deviation(gpa5, gpa_mean);

	// calculate variance and standard deviation of gpas
	double gpa_variance = calculate_variance(
	    deviation1, deviation2, deviation3, deviation4, deviation5, 5);
	double gpa_std = calculate_standard_deviation(gpa_variance);

	// write standard deviation to file
	print_double(outfile, gpa_std);

	// find min and max of gpas
	double gpa_min = find_min(gpa1, gpa2, gpa3, gpa4, gpa5);
	double gpa_max = find_max(gpa1, gpa2, gpa3, gpa4, gpa5);

	// write min and max to file
	print_double(outfile, gpa_min);
	print_double(outfile, gpa_max);

	// close file streams!!!
	fclose(infile);
	fclose(outfile);

	return 0;
}

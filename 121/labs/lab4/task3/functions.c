#include "headers.h"

double read_double(FILE *infile) {
	double data;
	fscanf(infile, "%lf", &data);

	return data;
}

double average(double nums[]) {
	double sum = 0;
	for (int i = 0; i < 5; ++i)
		sum += nums[i];

	return sum / 5;
}

double max(double nums[]) {
	double max = nums[0];
	for (int i = 1; i < 5; ++i) {
		if (nums[i] > max)
			max = nums[i];
	}

	return max;
}

double min(double nums[]) {
	double min = nums[0];
	for (int i = 1; i < 5; ++i) {
		if (nums[i] < min)
			min = nums[i];
	}

	return min;
}

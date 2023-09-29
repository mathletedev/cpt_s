#include <float.h>
#include <stdio.h>

int main(void) {
	FILE *infile = fopen("input.txt", "r");

	double max = 0, min = DBL_MAX;

	while (!feof(infile)) {
		double data;
		if (fscanf(infile, "%lf", &data) == EOF)
			break;

		if (data > max)
			max = data;
		if (data < min)
			min = data;
	}

	printf("max: %lf\n", max);
	printf("min: %lf\n", min);

	fclose(infile);

	return 0;
}

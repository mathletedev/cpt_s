#include <stdio.h>

int main(void) {
	FILE *infile = fopen("data.txt", "r");
	FILE *outfile = fopen("output.txt", "w");

	/* Fill in the code to open a file. Make sure you check that the file
	was open successfully. */
	int num_values = 0;
	double sum_values = 0;
	while (!feof(infile)) {
		/* Read in the real values. */
		double data;
		if (fscanf(infile, "%lf", &data) == EOF)
			break;

		/* Keep track of the number of values read and the sum of the
		 * values. */
		++num_values;
		sum_values += data;
	}

	/* Output average to a file named "output.txt". */
	fprintf(outfile, "%lf\n", sum_values / num_values);

	/* Close your files. */
	fclose(infile);
	fclose(outfile);

	return 0;
}

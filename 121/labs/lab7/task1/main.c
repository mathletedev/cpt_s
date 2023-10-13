#include "headers.h"

int main(void) {
	FILE *infile = fopen("input.txt", "r");
	FILE *outfile = fopen("output.txt", "w");

	int month, year, number;
	double hours;
	fscanf(infile, "%d%d%d%lf", &month, &year, &number, &hours);

	double total_cost, average_cost;
	charges(hours, &total_cost, &average_cost);

	fprintf(outfile, "Total cost: $%.2lf\n", total_cost);
	fprintf(outfile, "Average cost: $%.2lf/hour\n", average_cost);

	fclose(infile);
	fclose(outfile);

	return 0;
}

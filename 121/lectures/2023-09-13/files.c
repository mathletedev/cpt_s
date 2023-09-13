#include <stdio.h>

int main() {
	int scale;
	double x1, x2;
	FILE *fp_in = NULL, *fp_out = NULL;

	// printf("Enter an integer and two doubles: ");
	fp_in = fopen("input.txt", "r");
	fscanf(fp_in, "%d%lf%lf", &scale, &x1, &x2);
	fclose(fp_in);

	fp_out = fopen("output.txt", "w");
	fprintf(fp_out, "%lf\n", x1 * scale);
	fprintf(fp_out, "%lf\n", x2 * scale);
	fclose(fp_out);

	return 0;
}

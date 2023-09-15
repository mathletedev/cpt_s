#include <stdio.h>

#define __DEBUG__

int main() {
	char name_in[80], name_out[80];
	int scale;
	double x1, x2;
	FILE *fp_in = NULL, *fp_out = NULL;

	printf("Enter input file name: ");
	scanf("%s", name_in);

	// printf("Enter an integer and two doubles: ");
	fp_in = fopen(name_in, "r");
	fscanf(fp_in, "%d%lf%lf", &scale, &x1, &x2);
	fclose(fp_in);

#ifdef __DEBUG__
	printf("Read %d, %lf, %lf\n", scale, x1, x2);
#endif

	printf("Enter output file name: ");
	scanf("%s", name_out);

	fp_out = fopen(name_out, "w");
	fprintf(fp_out, "%lf\n", x1 * scale);
	fprintf(fp_out, "%lf\n", x2 * scale);
	fclose(fp_out);

	return 0;
}

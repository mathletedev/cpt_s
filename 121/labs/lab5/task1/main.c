#include <stdio.h>

int main(void) {
	FILE *infile = fopen("salaries.txt", "r");

	double sum = 0;
	for (int i = 0; i < 4; ++i) {
		double data;
		fscanf(infile, "%lf", &data);

		sum += data;
	}

	char res = 'l';
	if (sum >= 15000)
		res = 'm';
	if (sum > 200000)
		res = 'h';

	printf("%c\n", res);

	fclose(infile);

	return 0;
}

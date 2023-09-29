#include "headers.h"

int main(void) {
	FILE *infile = fopen("input.txt", "r");
	FILE *outfile = fopen("output.txt", "w");

	int a = abs(read_int(infile));
	int b = abs(read_int(infile));

	fprintf(outfile, "%d\n", gcd_for(a, b));
	fprintf(outfile, "%d\n", gcd_while(a, b));

	fclose(infile);
	fclose(outfile);

	return 0;
}

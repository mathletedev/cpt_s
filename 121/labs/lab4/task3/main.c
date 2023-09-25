#include "headers.h"

int main(void) {
	FILE *infile = fopen("input.txt", "r");

	double nums[5];
	char selection;

	for (int i = 0; i < 5; ++i)
		nums[i] = read_double(infile);

invalid:;
	printf(" 1) Average\n");
	printf(" 2) High value\n");
	printf(" 3) Low value\n");
	printf("Select option above: ");

	scanf(" %c", &selection);
	switch (selection) {
	case '1':
		printf("%lf", average(nums));
		break;
	case '2':
		printf("%lf", max(nums));
		break;
	case '3':
		printf("%lf", min(nums));
		break;
	default:
		printf("Invalid input: Must be 1, 2, or 3\n");
		goto invalid;
	}

	fclose(infile);

	return 0;
}

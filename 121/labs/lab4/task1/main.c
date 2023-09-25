#include "headers.h"

int main(void) {
	FILE *infile = fopen("input.txt", "r");

	double age, weight, height;
	char gender;

	age = read_double(infile);
	gender = read_char(infile);
	weight = read_double(infile);
	height = read_double(infile);

	double bmr = calculate_bmr(age, gender, weight, height);
	if (bmr == -1) {
		printf("Invalid input: Gender must be either 'M' or 'W'\n");
		return 1;
	}

	int level;
	printf("Activity levels:\n");
	printf(" 1) Sedentary\n");
	printf(" 2) Low\n");
	printf(" 3) Moderate\n");
	printf(" 4) High\n");
	printf(" 5) Extra\n");
	printf("Enter activity level: ");
	scanf("%d", &level);

	double multiplier = calculate_multiplier(level);
	if (multiplier == -1) {
		printf("Invalid input: Activity level must be an integer "
		       "between 1 and 5\n");
		return 1;
	}

	printf("Caloric intake: %lf\n", bmr * multiplier);

	fclose(infile);

	return 0;
}

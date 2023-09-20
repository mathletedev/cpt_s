#include "headers.h"

int read_score(FILE *infile) {
	int data;
	fscanf(infile, "%d", &data);

	return data;
}

char letter_grade(int score) {
	char letter = 'F';
	if (score >= 90)
		letter = 'A';
	else if (score >= 80)
		letter = 'B';
	else if (score >= 70)
		letter = 'C';
	else if (score >= 60)
		letter = 'D';

	return letter;
}

#include "headers.h"

int main(void) {
	FILE *input_stream = fopen("scores.txt", "r"),
	     *output_stream = fopen("grades.dat", "w");
	int score1, score2, score3;
	char grade1, grade2, grade3;

	score1 = read_score(input_stream);
	score2 = read_score(input_stream);
	score3 = read_score(input_stream);

	grade1 = letter_grade(score1);
	grade2 = letter_grade(score2);
	grade3 = letter_grade(score3);

	fprintf(output_stream, "%d %c\n", score1, grade1);
	fprintf(output_stream, "%d %c\n", score2, grade2);
	fprintf(output_stream, "%d %c\n", score3, grade3);

	fclose(input_stream);
	fclose(output_stream);
}

#include <stdio.h>

int main(void) {
	int count = 0, sum_scores = 0, score = 0;
	double avg_scores = 0.0;
	FILE *input_stream = fopen("scores.txt", "r");

	if (input_stream != NULL) {
		// feof() checks if EOF is reached
		while (!feof(input_stream)) {
			fscanf(input_stream, "%d", &score);

			sum_scores += score;
			++count;
		}
	}

	avg_scores = (double)sum_scores / count;
	printf("Average score: %lf\n", avg_scores);

	return 0;
}

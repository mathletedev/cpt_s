/*
 * Programming Assignment 1
 * Author: Neal Wang
 * Lab: 05
 * Due date: 2024-01-24
 * Fitbit data analyser
 */

#include "headers.h"

int main(void) {
	// open files
	FILE *infile = fopen("FitbitData.csv", "r");
	if (!infile) {
		puts("Failed to open FitbitData.csv");
		return 1;
	}
	FILE *outfile = fopen("Results.csv", "w");
	if (!outfile) {
		puts("Failed to open Results.csv");
		return 1;
	}

	// get target
	char line[MAX_LINE];
	fgets(line, MAX_LINE, infile);

	char target[10];
	// find second column
	strtok(line, ",");
	strcpy(target, strtok(NULL, ","));

	// consume header row
	fgets(line, MAX_LINE, infile);

	// 24 hours of data, 60 mins per hour
	FitbitData data[NUM_POINTS];
	int i = 0;
	char *prev_minute = NULL;
	while (fgets(line, MAX_LINE, infile) != NULL) {
		FitbitData *curr = data + i;

		strcpy(curr->patient, my_strtok(line, ','));
		// not target, discard line
		if (strcmp(curr->patient, target) != 0)
			continue;

		strcpy(curr->minute, my_strtok(NULL, ','));
		// duplicate, discard line
		if (prev_minute != NULL &&
		    strcmp(curr->minute, prev_minute) == 0)
			continue;
		prev_minute = curr->minute;

		char *curr_tok;

		curr_tok = my_strtok(NULL, ',');
		// set to invalid if value is empty
		curr->calories =
		    is_empty(curr_tok) ? INVALID : strtod(curr_tok, NULL);
		curr_tok = my_strtok(NULL, ',');
		curr->distance =
		    is_empty(curr_tok) ? INVALID : strtod(curr_tok, NULL);
		curr_tok = my_strtok(NULL, ',');
		curr->floors = is_empty(curr_tok) ? INVALID : atoi(curr_tok);
		curr_tok = my_strtok(NULL, ',');
		curr->heart_rate =
		    is_empty(curr_tok) ? INVALID : atoi(curr_tok);
		curr_tok = my_strtok(NULL, ',');
		curr->steps = is_empty(curr_tok) ? INVALID : atoi(curr_tok);
		curr_tok = my_strtok(NULL, ',');
		// replace invalid sleep with 0
		curr->sleep_level =
		    (Sleep)(is_empty(curr_tok) ? 0 : atoi(curr_tok));

		++i;
	}

	double total_calories, total_distance;
	unsigned int total_floors, total_steps;
	int sum_heart_rate, num_heart_rate;
	unsigned int max_steps = 0;
	// linked list for max steps minutes
	Node *head = NULL;
	unsigned int poorest_sleep = 0, curr_sleep = 0;
	char *poorest_start = NULL, *poorest_end = NULL;
	char *curr_start = NULL, *curr_end = NULL;
	for (int j = 0; j < i; ++j) {
		FitbitData *curr = data + j;

		if (curr->calories != INVALID)
			total_calories += curr->calories;

		if (curr->distance != INVALID)
			total_distance += curr->distance;

		if (curr->floors != INVALID)
			total_floors += curr->floors;

		if (curr->heart_rate != INVALID) {
			sum_heart_rate += curr->heart_rate;
			++num_heart_rate;
		}

		if (curr->steps != INVALID) {
			total_steps += curr->steps;

			if (curr->steps > max_steps) {
				// reset linked list
				clean(&head);
				insert_end(&head, curr->minute);

				max_steps = curr->steps;
			} else if (curr->steps == max_steps)
				insert_end(&head, curr->minute);
		}

		if (curr->sleep_level > 1) {
			curr_sleep += curr->sleep_level;

			if (curr_start == NULL)
				curr_start = curr->minute;
			curr_end = curr->minute;
		} else {
			// new poorest sleep candidate
			if (curr_sleep > poorest_sleep) {
				poorest_start = curr_start;
				poorest_end = curr_end;
			}

			curr_sleep = 0;
			curr_start = NULL;
		}
	}

	double average_heart_rate = (double)sum_heart_rate / num_heart_rate;

	fprintf(outfile,
		"Total Calories,Total Distance,Total Floors,Total Steps,Avg "
		"Heartrate,Max Steps (minute(s)),Sleep\n");
	fprintf(outfile, "%lf,%lf,%d,%d,%lf,", total_calories, total_distance,
		total_floors, total_steps, average_heart_rate);
	// write poorest sleep minutes
	write_list(outfile, head);
	fprintf(outfile, ",%s:%s\n", poorest_start, poorest_end);

	for (int j = 0; j < i; ++j) {
		FitbitData *curr = data + j;

		fprintf(outfile, "%s,%s,", curr->patient, curr->minute);

		// replace invalid data with "N/A"
		if (curr->calories == INVALID)
			fprintf(outfile, "N/A,");
		else
			fprintf(outfile, "%lf,", curr->calories);

		if (curr->distance == INVALID)
			fprintf(outfile, "N/A,");
		else
			fprintf(outfile, "%lf,", curr->distance);

		if (curr->floors == INVALID)
			fprintf(outfile, "N/A,");
		else
			fprintf(outfile, "%d,", curr->floors);

		if (curr->heart_rate == INVALID)
			fprintf(outfile, "N/A,");
		else
			fprintf(outfile, "%d,", curr->heart_rate);

		if (curr->steps == INVALID)
			fprintf(outfile, "N/A,");
		else
			fprintf(outfile, "%d,", curr->steps);

		fprintf(outfile, "%d\n", curr->sleep_level);
	}

	// close files
	fclose(infile);
	fclose(outfile);

	return 0;
}

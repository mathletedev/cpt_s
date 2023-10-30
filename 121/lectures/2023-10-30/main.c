#include "headers.h"

int main(void) {
	FILE *input_stream = fopen("data.csv", "r");
	if (input_stream == NULL)
		return 1;

	char lines[MAX_ROWS][MAX_COLS] = {{'\0'}};

	StudentRecord arr_students[10];

	int i = 0;
	while (fgets(lines[i], MAX_COLS, input_stream)) {
		arr_students[i].id = atoi(strtok(lines[i], ","));
		strcpy(arr_students[i].last_name, strtok(NULL, ","));
		strcpy(arr_students[i].first_name, strtok(NULL, ","));
		arr_students[i].gpa = atof(strtok(NULL, ","));

		++i;
	}

	write_students(arr_students, i);

	return 0;
}

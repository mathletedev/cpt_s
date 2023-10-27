#include "headers.h"

int main(void) {
	FILE *input_stream = fopen("data.csv", "r");
	if (input_stream == NULL)
		return 1;

	char lines[MAX_ROWS][MAX_COLS] = {{'\0'}};
	int curr_line = 0;
	StudentRecord student1;
	// StudentRecord student2 = init_student_record();
	StudentRecord student2;
	init_student_record_ptr(&student2);

	printf("Student 2: id %d, last name %s, first name %s, gpa %.2lf\n",
	       student2.id, student2.last_name, student2.first_name,
	       student2.gpa);

	while (fgets(lines[curr_line], MAX_COLS, input_stream)) {
		puts(strtok(lines[curr_line], ","));
		puts(strtok(NULL, ","));
		puts(strtok(NULL, ","));

		// use a pointer, can't assign to char array
		char *gpa_ptr = NULL;
		gpa_ptr = strtok(NULL, "\n");
		puts(gpa_ptr);

		++curr_line;
	}

	return 0;
}

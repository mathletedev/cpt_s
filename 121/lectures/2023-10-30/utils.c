#include "headers.h"

StudentRecord init_student_record(void) {
	StudentRecord sr;

	printf("Enter ID: ");
	scanf("%d", &sr.id);
	printf("Enter last name: ");
	scanf("%s", sr.last_name);
	printf("Enter first name: ");
	scanf("%s", sr.first_name);
	printf("Enter GPA: ");
	scanf("%lf", &sr.gpa);

	return sr;
}

void init_student_record_ptr(StudentRecord *sr) {
	printf("Enter ID: ");
	scanf("%d", &sr->id);
	printf("Enter last name: ");
	scanf("%s", sr->last_name);
	printf("Enter first name: ");
	scanf("%s", sr->first_name);
	printf("Enter GPA: ");
	scanf("%lf", &sr->gpa);
}

void write_students(StudentRecord *arr, size_t size) {
	for (int i = 0; i < size; ++i) {
		printf("arr[%d].id: %d\n", i, arr[i].id);
		printf("arr[%d].last_name: %s\n", i, arr[i].last_name);
		printf("arr[%d].first_name: %s\n", i, arr[i].first_name);
		printf("arr[%d].gpa: %.2lf\n", i, arr[i].gpa);
	}
}

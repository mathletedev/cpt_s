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

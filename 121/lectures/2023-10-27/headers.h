#ifndef HEADERS_H
#define HEADERS_H

#include <stdio.h>
#include <string.h>

#define MAX_ROWS 300
#define MAX_COLS 100

typedef struct StudentRecord {
	int id;
	char last_name[30];
	char first_name[30];
	double gpa;
} StudentRecord;

StudentRecord init_student_record(void);
void init_student_record_ptr(StudentRecord *sr);

#endif

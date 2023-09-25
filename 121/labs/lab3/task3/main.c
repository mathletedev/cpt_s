#include "functions.h"
#include "headers.h"

int main(void) {
	double exam1 = read("exam 1");
	double exam2 = read("exam 2");
	double lab1 = read("lab 1");
	double lab2 = read("lab 2");
	double project1 = read("project 1");
	double project2 = read("project 2");

	double exam_avg = average(exam1, exam2);
	double lab_avg = average(lab1, lab2);
	double project_avg = average(project1, project2);

	display_average("exam", exam_avg);
	display_average("lab", lab_avg);
	display_average("project", project_avg);

	double weighted_avg = weighted_average(exam_avg, lab_avg, project_avg);

	display_weighted_average(weighted_avg);

	return 0;
}

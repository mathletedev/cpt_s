#include <stdio.h>

double f(double x) {
	// return value of a function
	return x * x - 4 * x + 4;
}

double get_grade(void) {
	double grade;

	printf("Enter the grade for the course: ");
	scanf("%lf", &grade);

	return grade;
};

int get_credits(void) {
	int credits;

	printf("Enter the number of credits for the course: ");
	scanf("%d", &credits);

	return credits;
}

double compute_weighted_gp(double grade1, double grade2, double grade3,
			   int credits1, int credits2, int credits3) {
	return (grade1 * credits1) + (grade2 * credits2) + (grade3 * credits3);
}

double compute_gpa(double weighted_gp, double total_credits) {
	return weighted_gp / total_credits;
}

void display_gpa(double gpa) { printf("GPA: %.2lf\n", gpa); }

int main(void) {
	// function example
	double x;

	printf("Enter x: ");
	scanf("%lf", &x);

	printf("Result: %lf\n", f(x));

	// gpa example
	int credits1, credits2, credits3;
	double grade1, grade2, grade3;
	double weighted_gp, total_credits, gpa;

	/* // get the grade points and gredits */
	/* printf("Enter grade and credits for couse 1: "); */
	/* scanf("%lf%d", &grade1, &credits1); */

	/* printf("Enter grade and credits for couse 2: "); */
	/* scanf("%lf%d", &grade2, &credits2); */

	/* printf("Enter grade and credits for couse 3: "); */
	/* scanf("%lf%d", &grade3, &credits3); */

	/* // compute grade point weighted by credit hours */
	/* weighted_gp = */
	/*     (grade1 * credits1) + (grade2 * credits2) + (grade3 * credits3);
	 */

	/* // sum credits over all classes */
	/* total_credits = credits1 + credits2 + credits3; */

	/* // compute gpa as average */
	/* gpa = weighted_gp / total_credits; */

	grade1 = get_grade();
	credits1 = get_credits();
	grade2 = get_grade();
	credits2 = get_credits();
	grade3 = get_grade();
	credits3 = get_credits();

	weighted_gp = compute_weighted_gp(grade1, grade2, grade3, credits1,
					  credits2, credits3);
	total_credits = credits1 + credits2 + credits3;
	gpa = compute_gpa(weighted_gp, total_credits);

	display_gpa(gpa);

	return 0;
}

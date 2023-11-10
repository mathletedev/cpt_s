#include "headers.h"

int main(void) {
	FILE *infile = fopen("payroll.txt", "r");
	FILE *outfile = fopen("paid.txt", "w");

	Employee employees[200];

	double total = 0;
	double average = 0;
	double max = -INFINITY;
	double min = INFINITY;

	int index = 0;
	while (1) {
		Employee *employee = employees + index;
		if (fgets(employee->name, 100, infile) == NULL)
			break;
		employee->name[strlen(employee->name) - 1] = '\0';

		fscanf(infile, " %c", &employee->title);
		fscanf(infile, "%lf", &employee->hours_worked);
		fscanf(infile, "%lf", &employee->payrate);

		char consumed;
		fscanf(infile, "%c", &consumed);

		double no_overtime = employee->hours_worked;
		if (no_overtime > OVERTIME)
			no_overtime = OVERTIME;

		double overtime = employee->hours_worked - OVERTIME;
		if (overtime < 0)
			overtime = 0;

		employee->payment = no_overtime * employee->payrate +
				    (employee->title == 'B' ? 1.5 : 1.8) *
					overtime * employee->payrate;

		total += employee->payment;
		if (employee->payment > max)
			max = employee->payment;
		if (employee->payment < min)
			min = employee->payment;

		++index;
	}
	average = total / index;

	fprintf(outfile, "Total: $%.2lf\n", total);
	fprintf(outfile, "Average: $%.2lf\n", average);
	fprintf(outfile, "Max: $%.2lf\n", max);
	fprintf(outfile, "Min: $%.2lf\n", min);

	fclose(infile);
	fclose(outfile);

	return 0;
}

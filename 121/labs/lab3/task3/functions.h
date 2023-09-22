#ifndef functions_h
#define functions_h

#include <stdio.h>

double read(char *prompt);
double average(double num1, double num2);
void display_average(char *type, double avg);
double weighted_average(double exam_avg, double lab_avg, double project_avg);
void display_weighted_average(double weighted_avg);

#endif

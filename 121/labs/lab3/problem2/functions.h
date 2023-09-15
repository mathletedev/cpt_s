#ifndef functions_h
#define functions_h

#define G 32.17

#include <math.h>
#include <stdio.h>

double read(char *prompt);
double calculate_time(double distance, double velocity, double theta);
double calculate_height(double velocity, double theta, double time);

#endif

#ifndef headers_h
#define headers_h

#include <stdio.h>

double read_double(FILE *infile);
char read_char(FILE *infile);

double calculate_bmr(double age, char gender, double weight, double height);
double calculate_multiplier(int level);

#endif

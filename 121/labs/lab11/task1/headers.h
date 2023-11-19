#ifndef HEADERS_H
#define HEADERS_H

#include <math.h>
#include <stdio.h>
#include <string.h>

#define OVERTIME 80

typedef struct employee {
	char name[100];
	char title;
	double hours_worked;
	double payrate;
	double payment;
} Employee;

#endif

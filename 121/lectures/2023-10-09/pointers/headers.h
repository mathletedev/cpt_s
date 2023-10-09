#ifndef headers_h
#define headers_h

#include <stdio.h>

int dispense_change(double cost, double payment, int *twenties_ptr,
		    int *tens_ptr, int *fives_ptr, int *ones_ptr,
		    int *quarters_ptr, int *dimes_ptr, int *nickels_ptr,
		    int *pennies_ptr);

#endif

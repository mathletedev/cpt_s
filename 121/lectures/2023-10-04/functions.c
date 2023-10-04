#include "headers.h"

void divide(int num, int den, int *result_ptr, int *remainder_ptr) {
	*result_ptr = num / den;
	*remainder_ptr = num % den;
}

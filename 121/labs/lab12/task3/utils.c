#include "headers.h"

void reverse(char *low, char *high) {
	if (low >= high)
		return;

	char tmp = *low;
	*low = *high;
	*high = tmp;

	reverse(low + 1, high - 1);
}

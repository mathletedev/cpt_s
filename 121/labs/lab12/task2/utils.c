#include "headers.h"

int sum(int n) {
	if (n == 0)
		return 0;

	return (n % 10) + sum(n / 10);
}

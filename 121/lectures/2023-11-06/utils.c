#include "headers.h"

int multiply_iterative(int m, int n) {
	int res = 0;
	while (n > 0) {
		res += m;
		--n;
	}

	return res;
}

int multiply_recursive(int m, int n) {
	if (n == 1)
		return m;
	return m + multiply_recursive(m, n - 1);
}

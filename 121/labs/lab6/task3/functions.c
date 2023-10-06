#include "headers.h"

int fibonacci(int n) {
	int a = 0, b = 1;

	for (int i = 1; i < n; ++i) {
		int tmp = b;
		b += a;
		a = tmp;
	}

	return a;
}

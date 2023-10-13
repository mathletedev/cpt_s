#include "headers.h"

double revenue(double t) { return 203.265 * pow(1.071, t); }

int predict(double value) {
	int low = 0, high = 10000;

	while (low < high) {
		int mid = (low + high) / 2;

		if (revenue(mid) > value)
			high = mid;
		else
			low = mid + 1;
	}

	return 1984 + low;
}

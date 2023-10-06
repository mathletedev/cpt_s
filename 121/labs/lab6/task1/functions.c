#include "headers.h"

int read_and_sum_ints(FILE *infile) {
	int sum = 0;

	int data;
	while (fscanf(infile, "%d", &data) != EOF)
		sum += data;

	return sum;
}

int is_prime(int n) {
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0)
			return 0;
	}

	return 1;
}

int sum_digits(int n) {
	int sum = 0;

	while (n > 0)
		sum += n % 10, n /= 10;

	return sum;
}

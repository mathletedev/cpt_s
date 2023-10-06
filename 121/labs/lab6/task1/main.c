#include "headers.h"

int main(void) {
	FILE *infile = fopen("input.txt", "r");

	int sum_a = read_and_sum_ints(infile);

	printf("sum of numbers: %d\n", sum_a);
	if (is_prime(sum_a))
		printf("%d is prime\n", sum_a);
	else
		printf("%d is not prime\n", sum_a);

	printf("\n");

	int sum_b = sum_digits(sum_a);

	printf("sum of digits: %d\n", sum_b);
	if (is_prime(sum_b))
		printf("%d is prime\n", sum_b);
	else
		printf("%d is not prime\n", sum_b);

	return 0;
}

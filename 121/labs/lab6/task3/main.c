#include "headers.h"

int main(void) {
	int N;
	printf("Enter the value of N: ");
	scanf("%d", &N);

	printf("The %dth Fibonacci number is %d\n", N, fibonacci(N));

	return 0;
}

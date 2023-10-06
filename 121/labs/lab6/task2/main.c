#include "headers.h"

int main(void) {
	int N;
	do {
		printf("Enter the value of N: ");
		scanf("%d", &N);
	} while (N < 0);

	printf("%d! = %d\n", N, factorial(N));

	return 0;
}

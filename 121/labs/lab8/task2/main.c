#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20
#define MAX_RAND 100

int main(void) {
	srand(time(NULL));

	int arr[N] = {0};

	for (int i = 0; i < N; ++i)
		arr[i] = rand() % MAX_RAND + 1;

	int frequency[MAX_RAND + 1] = {0};

	for (int i = 0; i < N; ++i)
		++frequency[arr[i]];

	for (int i = 1; i <= MAX_RAND; ++i)
		printf("%d: %d\n", i, frequency[i]);

	return 0;
}

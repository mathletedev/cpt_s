#include "headers.h"

int main(void) {
	srand(time(NULL));

	int target = gen_rand();

	int num_guesses = 0;
	while (1) {
		int guess;
		int valid = 1;
		do {
			if (!valid)
				printf("Your guess must be between -100 and "
				       "100.\n");
			valid = 0;

			printf("Enter your guess: ");
			scanf("%d", &guess);
		} while (guess < -100 || guess > 100);

		++num_guesses;

		if (guess == target)
			break;

		if (guess > target)
			printf("Your guess was too high.\n");
		else
			printf("Your guess was too low.\n");
		printf("\n");
	}

	printf("The number was %d!\n", target);
	printf("You guessed it in %d tries.\n", num_guesses);

	return 0;
}

#include <stdio.h>

int main(void) {
	int count = 0;
	do {
		printf("1. Display game\n");
		printf("2. Play game\n");
		printf("3. Exit\n");
		scanf("%d", &count);
	} while (count < 1 || count > 3);
}

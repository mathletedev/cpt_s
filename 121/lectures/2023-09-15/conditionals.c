#include <stdio.h>

int main(void) {
	int compare = 5 != 7;
	char ch = 'c';

	printf("compare: %d\n", compare);
	printf("chars: %d\n", ch < 'a');

	return 0;
}

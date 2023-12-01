#include <stdio.h>

int power2(int num, int pow) { return num << pow; }

int main(void) {
	int num, pow;
	printf("base: ");
	scanf("%d", &num);
	printf("pow: ");
	scanf("%d", &pow);

	printf("%d", power2(num, pow));

	return 0;
}

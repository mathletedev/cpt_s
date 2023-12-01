#include <stdio.h>

#define BITS 32

void write_bin(int dec) {
	for (int i = BITS - 1; i >= 0; --i)
		printf("%d", ((dec & (1 << i)) > 0));
	printf("\n");
}

int main(void) {
	int num;
	printf("num: ");
	scanf("%d", &num);

	write_bin(num);

	num >>= 4;

	write_bin(num);

	return 0;
}

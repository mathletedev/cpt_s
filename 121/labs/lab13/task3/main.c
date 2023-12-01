#include <stdio.h>

void write_bin(int dec, int bits) {
	for (int i = bits - 1; i >= 0; --i)
		printf("%d", ((dec & (1 << i)) > 0));
	printf("\n");
}

unsigned int pack_characters(char *chars) {
	unsigned int res = 0;
	for (int i = 0; i < 4; ++i)
		res |= chars[i] << (i * 8);

	return res;
}

int main(void) {
	char chars[4] = {};

	printf("chars: ");
	for (int i = 0; i < 4; ++i)
		scanf("%c", chars + i);

	for (int i = 0; i < 4; ++i)
		write_bin(chars[i], 8);

	unsigned int packed = pack_characters(chars);
	write_bin(packed, 32);

	return 0;
}

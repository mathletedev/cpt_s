#include <stdio.h>

int my_strlen(char *str) {
	int res = 0;
	while (str[res++] != '\0')
		;

	return res - 1;
}

void my_strcat(char *dest, const char *src) {
	char *start = dest + my_strlen(dest);

	for (int i = 0; src[i] != '\0'; ++i)
		start[i] = src[i];
}

void sort(char *str) {
	int size = my_strlen(str);

	for (int i = 0; i < size - 1; ++i) {
		for (int j = 0; j < size - 1 - i; ++j) {
			if (str[j] > str[j + 1]) {
				char tmp = str[j];
				str[j] = str[j + 1];
				str[j + 1] = tmp;
			}
		}
	}
}

int main(void) {
	char string1[] = "cougar";
	char string2[] = "husky";

	// solution 1
	char res1[100];
	my_strcat(res1, string1);
	my_strcat(res1, string2);
	sort(res1);
	puts(res1);

	return 0;
}

#include <stdio.h>
#include <stdlib.h>

int my_strlen(const char *str) {
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

void my_dynstrcat(char **dest, const char *src) {
	size_t dest_len = *dest == NULL ? 0 : my_strlen(*dest);
	*dest = (char *)realloc(*dest,
				(dest_len + my_strlen(src) + 1) * sizeof(char));

	my_strcat(*dest, src);
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
	char string1[100] = "cougar";
	char string2[] = "husky";

	// solution 1
	char res1[100];
	my_strcat(res1, string1);
	my_strcat(res1, string2);
	sort(res1);
	puts(res1);

	// solution 2
	char *res2 = NULL;
	my_dynstrcat(&res2, string1);
	my_dynstrcat(&res2, string2);
	sort(res2);
	puts(res2);

	// solution 3
	my_strcat(string1, string2);
	sort(string1);
	puts(string1);

	return 0;
}

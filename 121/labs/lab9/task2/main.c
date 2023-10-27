#include "headers.h"

int main(void) {
	puts("---- strcpy ----");
	char my_string1[100] = "";
	char my_string2[] = "abcdefg";
	puts(my_strcpy(my_string1, my_string2));

	puts("---- strcat ----");
	char my_string3[100] = "rain";
	char my_string4[] = "bow";
	puts(my_strcat(my_string3, my_string4));

	puts("---- strcmp ----");
	printf("%d\n", my_strcmp("cat", "coug"));
	printf("%d\n", my_strcmp("coug", "cat"));
	printf("%d\n", my_strcmp("coug", "cougar"));
	printf("%d\n", my_strcmp("cougar", "coug"));
	printf("%d\n", my_strcmp("coug", "coug"));

	puts("---- strcmp ----");
	printf("%d\n", my_strlen("string"));

	return 0;
}

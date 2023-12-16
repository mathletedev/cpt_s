#include "headers.h"

int main(void) {
	FILE *infile = fopen("input.txt", "r");
	FILE *outfile = fopen("output.txt", "w");

	char string[100];
	char c;
	int res;

	puts("---- my_fgets ----");
	my_fgets(string, 100, infile);
	puts(string);
	my_fgets(string, 8, infile);
	puts(string);
	NEWLINE;

	puts("---- my_fputs ----");
	my_fputs("my_fputs()\n", outfile);
	puts("Wrote my_fputs() to outfile");
	NEWLINE;

	puts("---- my_fgetc ----");
	c = my_fgetc(infile);
	printf("char: %c\nascii: %d\n", c, c);
	NEWLINE;

	puts("---- my_fputc ----");
	printf("Wrote %c to outfile\n", my_fputc(c, outfile));
	NEWLINE;

	puts("---- my_gets ----");
	printf("Enter a string: ");
	my_gets(string);
	printf("Echo: %s\n", string);
	NEWLINE;

	puts("---- my_puts ----");
	res = my_puts("my_puts()");
	printf("Wrote %d characters\n", res);
	NEWLINE;

	puts("---- my_getchar ----");
	printf("Enter a character: ");
	c = my_getchar();
	printf("Echo: %c\n", c);
	NEWLINE;

	puts("---- my_putchar ----");
	my_putchar('c');
	NEWLINE;
	NEWLINE;

	puts("---- my_strcpy ----");
	my_strcpy(string, "my_strcpy()");
	printf("Copied: %s\n", string);
	NEWLINE;

	puts("---- my_strncpy ----");
	my_strncpy(string, "my_strncpy()", 100);
	printf("Copied: %s\n", string);
	NEWLINE;

	puts("---- my_strcat ----");
	my_strcpy(string, "cat");
	my_strcat(string, "dog");
	printf("cat + dog = %s\n", string);
	NEWLINE;

	puts("---- my_strncpy ----");
	my_strcpy(string, "cat");
	my_strncat(string, "dog", 2);
	printf("cat + do = %s\n", string);
	my_strncat(string, "fish", 10);
	printf("catdo + fish = %s\n", string);
	NEWLINE;

	puts("---- my_strcmp ----");
	printf("coug > husky: %d\n", my_strcmp("coug", "husky"));
	NEWLINE;

	puts("---- my_strncmp ----");
	printf("coug > husky: %d\n", my_strncmp("coug", "husky", 2));
	NEWLINE;

	puts("---- my_strlen ----");
	printf("Length of \"volcano\": %d\n", my_strlen("volcano"));
	NEWLINE;

	fclose(infile);
	fclose(outfile);

	return 0;
}

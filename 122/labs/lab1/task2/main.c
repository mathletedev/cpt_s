#include <stdio.h>

void reverse_print(char *str) {
	if (str[0] == '\0')
		return;
	reverse_print(str + 1);

	printf("%c", str[0]);
}

int contains(const char *str, char c) {
	while (*str != '\0') {
		if (*str == c)
			return 1;
		++str;
	}

	return 0;
}

char *my_strtok(char *str, const char *delim) {
	static char *p_token;
	if (str != NULL)
		p_token = str;

	while (contains(delim, *p_token)) {
		++p_token;
		if (*p_token == '\0')
			return NULL;
	}

	char *beginning = p_token;

	while (!contains(delim, *p_token)) {
		++p_token;
		if (*p_token == '\0')
			break;
	}
	*p_token = '\0';
	++p_token;

	return beginning;
}

int main(void) {
	reverse_print("Hello, world!");
	printf("\n");

	char string[] = "Hello World, I am?in;CptS 122";
	puts(my_strtok(string, " ,;?"));
	puts(my_strtok(NULL, " ,;?"));
	puts(my_strtok(NULL, " ,;?"));
	puts(my_strtok(NULL, " ,;?"));
	puts(my_strtok(NULL, " ,;?"));
	puts(my_strtok(NULL, " ,;?"));

	return 0;
}

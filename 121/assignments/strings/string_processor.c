#include "headers.h"

/*
 * Finds the smaller of two numbers
 *
 * Parameters:
 * - int a: First number
 * - int b: Second number
 *
 * Returns the smaller of a and b
 */
int min(int a, int b) { return (a < b) ? a : b; }

/*
 * Reads up to n characters from file
 *
 * Parameters:
 * - char *s: String to read into
 * - int n: Maximum number of characters to read
 * - FILE *stream: file to read from
 *
 * Post-condition: s is written into
 *
 * Returns s (NULL if unsuccessful)
 */
char *my_fgets(char *s, int n, FILE *stream) {
	STREAM_GUARD(NULL);

	int i;
	for (i = 0; i < n - 1; ++i) {
		char c;
		int res = fscanf(stream, "%c", &c);
		if (res == EOF)
			break;
		if (res == 0)
			return NULL;

		*(s + i) = c;

		if (c == '\n')
			break;
	}

	*(s + i + 1) = '\0';
	return s;
}

/*
 * Writes s to file
 *
 * Parameters:
 * - const char *s: String to write
 * - FILE *stream: File to write to
 *
 * Post-condition: s is written to file
 *
 * Returns number of characters written (MY_EOF if unsuccessful)
 */
int my_fputs(const char *s, FILE *stream) {
	STREAM_GUARD(MY_EOF);

	fprintf(stream, "%s", s);
	return my_strlen(s);
}

/*
 * Reads one character from file
 *
 * Parameters:
 * - FILE *stream: File to read from
 *
 * Returns ASCII value of read character (MY_EOF if unsuccessful)
 */
int my_fgetc(FILE *stream) {
	STREAM_GUARD(MY_EOF);

	char c;
	int res = fscanf(stream, "%c", &c);
	if (res == EOF)
		return MY_EOF;

	return c;
}

/*
 * Writes one character to file
 *
 * Parameters:
 * - int c: Character to write
 * - FILE *stream: File to write to
 *
 * Post-condition: c is written to file
 *
 * Returns ASCII value of written character (MY_EOF if unsuccessful)
 */
int my_fputc(int c, FILE *stream) {
	STREAM_GUARD(MY_EOF);

	fprintf(stream, "%c", c);
	return c;
}

/*
 * Reads a string from stdin
 *
 * Pre-condition: String is less than 1,000,000,000 characters long
 *
 * Parameters:
 * - char *s: String to read into
 *
 * Post-condition: s is written into
 *
 * Returns s
 */
char *my_gets(char *s) {
	// use stdin as stream
	my_fgets(s, 1e9, stdin);
	s[my_strlen(s) - 1] = '\0';

	return s;
}

/*
 * Writes a string to stdout
 *
 * Parameters:
 * - char *s: String to write
 *
 * Returns number of characters written
 */
int my_puts(const char *s) {
	printf("%s\n", s);
	return my_strlen(s);
}

/*
 * Reads one character from stdin
 *
 * Returns ASCII value of character
 */
int my_getchar(void) {
	char c;
	scanf("%c", &c);

	return c;
}

/*
 * Writes one character to stdout
 *
 * Parameters:
 * - int c: Character to write
 *
 * Returns ASCII value of character
 */
int my_putchar(int c) {
	printf("%c", c);
	return c;
}

/*
 * Copies source into destination
 *
 * Pre-conditions:
 * - source is null-terminated
 * - destination has enough space
 *
 * Parameters:
 * - char *destination: String to copy into
 * - char *source: String to copy from
 *
 * Post-condition: destination is equal to source
 *
 * Returns destination
 */
char *my_strcpy(char *destination, const char *source) {
	for (int i = 0; i <= my_strlen(source); ++i)
		*(destination + i) = *(source + i);

	return destination;
}

/*
 * Copies n characters of source into destination
 *
 * Pre-condition:
 * - n is greater than the length of source + 1
 * - Length of destination is >= n
 *
 * Parameters:
 * - char *destination: String to copy into
 * - char *source: String to copy from
 * - int n: Number of characters to copy
 *
 * Post-conditions:
 * - n characters of source are copied into destination
 * - Remainder of destination is null-padded
 *
 * Returns destination
 */
char *my_strncpy(char *destination, const char *source, int n) {
	int seen_null = 0;

	for (int i = 0; i < n; ++i) {
		*(destination + i) = seen_null ? '\0' : *(source + i);

		if (*(source + i) == '\0')
			seen_null = 1;
	}

	return destination;
}

/*
 * Appends source to destination
 *
 * Pre-condition:
 * - source is null-terminated
 * - destination has enough space
 *
 * Parameters:
 * - char *destination: String to append to
 * - char *source: String to append
 *
 * Post-conditions: source is appended to destination
 *
 * Returns destination
 */
char *my_strcat(char *destination, const char *source) {
	// copy to end of destination
	my_strcpy(destination + my_strlen(destination), source);
	return destination;
}

/*
 * Appends n characters of source to destination
 *
 * Pre-condition: destination has enough space
 *
 * Parameters:
 * - char *destination: String to append to
 * - char *source: String to append
 * - int n: Number of characters to append
 *
 * Post-conditions: n characters of source are appended to destination
 *
 * Returns destination
 */
char *my_strncat(char *destination, const char *source, int n) {
	int end = my_strlen(destination);

	int i;
	for (i = 0; i < n; ++i) {
		if (*(source + i) == '\0')
			break;

		*(destination + end + i) = *(source + i);
	}

	*(destination + end + i) = '\0';
	return destination;
}

/*
 * Compares two strings
 *
 * Pre-condition: At least one string is null-terminated
 *
 * Parameters:
 * - const char *s1: First string
 * - const char *s2: Second string
 *
 * Returns:
 * - 1 if s1 > s2
 * - 0 if s1 = s2
 * - -1 if s1 < s2
 */
int my_strcmp(const char *s1, const char *s2) {
	for (int i = 0;; ++i) {
		if (*(s1 + i) == *(s2 + i)) {
			// reached end
			if (*(s1 + i) == '\0')
				return 0;
			continue;
		}

		// 1 is true, convert to -1 or 1
		return (*(s1 + i) > *(s2 + i)) * 2 - 1;
	}
}

/*
 * Compares the first n characters of two strings
 *
 * Parameters:
 * - const char *s1: First string
 * - const char *s2: Second string
 * - int n: Number of characters to compare
 *
 * Returns:
 * - 1 if s1 > s2
 * - 0 if s1 = s2
 * - -1 if s1 < s2
 */
int my_strncmp(const char *s1, const char *s2, int n) {
	for (int i = 0; i < n; ++i) {
		if (*(s1 + i) == *(s2 + i)) {
			if (*(s1 + i) == '\0')
				return 0;
			continue;
		}

		return (*(s1 + i) > *(s2 + i)) * 2 - 1;
	}

	return 0;
}

/*
 * Determines the length of a string
 *
 * Pre-condition: String is null-terminated
 *
 * Parameters:
 * - char *s: String to determine length of
 *
 * Returns the length of the string (excluding the null character)
 */
int my_strlen(const char *s) {
	int res = 0;
	// keep increasing res until null terminator is found
	while (*(s + ++res) != '\0')
		;

	return res;
}

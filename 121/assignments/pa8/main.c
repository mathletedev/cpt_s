#include "headers.h"

// Test cases for all tasks
int main(void) {
	puts("Task 1: String Concatenation");
	char str1[100] = "dog";
	char str2[100] = "cat";
	printf("dog + cat, n = 2: %s\n", my_str_n_cat(str1, str2, 2));
	strcpy(str1, "dog");
	printf("dog + cat, n = 8: %s\n", my_str_n_cat(str1, str2, 8));
	NEWLINE;

	puts("Task 2: Binary Search");
	int arr1[] = {1, 1, 2, 3, 5, 8, 13, 21};
	printf("arr1: ");
	for (int i = 0; i < 8; ++i)
		printf("%d, ", arr1[i]);
	NEWLINE;

	printf("5 in arr1: %d\n", binary_search(arr1, 8, 5));
	printf("21 in arr1: %d\n", binary_search(arr1, 8, 21));
	printf("1 in arr1: %d\n", binary_search(arr1, 8, 1));
	printf("4 in arr1: %d\n", binary_search(arr1, 8, 4));
	NEWLINE;

	puts("Task 3: Bubble Sort");
	char *arr2[] = {"red",	"orange", "yellow", "green",
			"blue", "indigo", "violet"};
	bubble_sort(arr2, 7);
	for (int i = 0; i < 7; ++i)
		puts(arr2[i]);
	NEWLINE;

	puts("Task 4: Palindrome");
	printf("racecar: %d\n", is_palindrome("racecar", 7));
	printf("kayak:   %d\n", is_palindrome("kayak", 5));
	printf("billy:   %d\n", is_palindrome("billy", 8));
	NEWLINE;

	puts("Task 5: Sum Primes");
	printf("n = 2:  %d\n", sum_primes(2));
	// 2 + 3 + 5 + 7 = 17
	printf("n = 10: %d\n", sum_primes(10));
	// 2 + 3 + 5 + 7 + 11 + 13 + 17 + 19 = 77
	printf("n = 20: %d\n", sum_primes(20));
	printf("n = 0:  %d\n", sum_primes(0));
	NEWLINE;

	puts("Task 6: Maximum Occurences");
	char str3[] = "test string";
	printf("str3: %s\n", str3);
	Occurences *occurences = malloc(sizeof(Occurences) * (ASCII_MAX + 1));
	for (int i = 0; i <= ASCII_MAX; ++i)
		occurences[i].num_occurences = 0;

	int max;
	char max_char;
	int res = maximum_occurences(str3, occurences, &max, &max_char);

	for (int c = 'a'; c <= 'z'; ++c) {
		if (occurences[c].num_occurences > 0)
			printf("%c) occurences: %3d, frequency: %3g\n", c,
			       occurences[c].num_occurences,
			       occurences[c].frequency);
	}
	for (int c = 'A'; c <= 'Z'; ++c) {
		if (occurences[c].num_occurences > 0)
			printf("%c) occurences: %3d, frequency: %3g\n", c,
			       occurences[c].num_occurences,
			       occurences[c].frequency);
	}
	for (int c = '0'; c <= '9'; ++c) {
		if (occurences[c].num_occurences > 0)
			printf("%c) occurences: %3d, frequency: %g\n", c,
			       occurences[c].num_occurences,
			       occurences[c].frequency);
	}
	printf("max occurences: %d\n", max);
	printf("character: %c\n", max_char);

	free(occurences);
	NEWLINE;

	puts("Task 7: Consecutive Integers");
	int arr3[4][5] = {{-5, 6, 0, 2, 2},
			  {2, 2, 2, 9, 3},
			  {3, 3, 2, 1, -8},
			  {7, -2, 6, 0, 4}};
	int *start;
	int max_length;
	max_consecutive_integers(arr3, 4, 5, &start, &max_length);
	printf("start: %p\n", start);
	printf("value @ start: %d\n", *start);
	printf("max length: %d\n", max_length);
	NEWLINE;

	return 0;
}

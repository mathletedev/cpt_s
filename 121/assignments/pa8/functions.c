#include "headers.h"

/*
 * Determines the length of a string
 *
 * Pre-conditions: String is null-terminated
 *
 * Parameters:
 * - char *string: String to determine length of
 *
 * Returns the length of the string
 */
int my_strlen(char *string) {
	int res = 0;
	// keep increasing res until null terminator is found
	while (*(string + ++res) != '\0')
		;

	return res;
}

/*
 * Concatenates up to n characters of src to the end of dest
 *
 * Pre-conditions: Size of dest is large enough to contain characters
 *
 * Parameters:
 * - char *dest: Destination string
 * - char *src: Source string
 * - int n: Number of characters to concatenate
 *
 * Returns a pointer to dest
 */
char *my_str_n_cat(char *dest, char *src, int n) {
	int len_src = my_strlen(src);
	int len_dest = my_strlen(dest);

	// do not copy more than src length
	if (len_src < n)
		n = len_src;

	// copy into next char of dest
	for (int i = 0; i < n; ++i)
		*(dest + len_dest + i) = *(src + i);
	// null terminate
	*(dest + len_dest + n) = '\0';

	return dest;
}

/*
 * Performs binary search on an array of integers
 *
 * Pre-conditions: arr is sorted in ascending order
 *
 * Parameters:
 * - int *arr: Integer array
 * - int n: Size of arr
 * - int target: Value to find
 *
 * Returns 1 if target is found in arr
 */
int binary_search(int *arr, int n, int target) {
	int low = 0, high = n;
	while (low < high) {
		int mid = (low + high) / 2;

		if (arr[mid] >= target)
			high = mid;
		else
			low = mid + 1;
	}

	return arr[low] == target;
}

/*
 * Performs bubble sort on an array of strings
 *
 * Post-conditions: arr is sorted in lexicographic order
 *
 * Parameters:
 * - char **arr: String array
 * - int n: Size of arr
 */
void bubble_sort(char **arr, int n) {
	int u = n;

	while (u > 1) {
		int c = 1;

		while (c < u) {
			if (strcmp(arr[c], arr[c - 1]) < 0) {
				char *tmp = arr[c];
				arr[c] = arr[c - 1];
				arr[c - 1] = tmp;
			}
			++c;
		}
		--u;
	}
}

/*
 * Determines if a string is a palindrome
 *
 * Parameters:
 * - char *string: String to check
 * - int length: Length of string
 *
 * Returns 1 if string is a palindrome
 */
int is_palindrome(char *string, int length) {
	// base case: single characters are always palindromes
	if (length <= 1)
		return 1;
	if (string[0] == string[length - 1])
		// move left and right bounds closer
		return is_palindrome(string + 1, length - 2);
	return 0;
}

/*
 * Computes the sum of all primes from 2 to n
 *
 * Parameters:
 * - int n: Number to sum to
 *
 * Returns the sum of all primes from 2 to n
 */
unsigned int sum_primes(unsigned int n) {
	// base cases
	if (n < 2)
		return 0;
	if (n == 2)
		return 2;

	int is_prime = 1;
	for (int x = 2; x * x <= n; ++x) {
		if (n % x == 0)
			is_prime = 0;
	}

	// add n if is prime
	return sum_primes(n - 1) + (is_prime ? n : 0);
}

/*
 * Finds the maximum occurences of a character in a string
 *
 * Post-conditions:
 * - occurences will be populated with correct values
 * - max and max_char will contain the max occurences
 *
 * Parameters:
 * - char *string: String to use
 * - Occurences *occurences: Array of occurences
 * - int *max: Pointer to max occurences
 * - char *max_char: Pointer to character with max occurences
 *
 * Returns 1 if successful
 */
int maximum_occurences(char *string, Occurences *occurences, int *max,
		       char *max_char) {
	*max = 0;

	int length = my_strlen(string);
	for (int i = 0; i < length; ++i) {
		// string can only have alphanumeric/whitespace characters
		if (!isalnum(string[i]) && string[i] != ' ')
			return 0;

		// index using ascii value
		++occurences[string[i]].num_occurences;
	}

	for (int c = 0; c <= ASCII_MAX; ++c) {
		if (occurences[c].num_occurences > *max) {
			*max = occurences[c].num_occurences;
			*max_char = c;
		}

		occurences[c].frequency =
		    (double)occurences[c].num_occurences / length;
	}

	return 1;
}

/*
 * Finds the longest sequence of consecutive integers in a 2D array
 *
 * Post-conditions: start and max_length will refer to the longest sequence
 *
 * Parameters:
 * - int *integers[]: 2D array of integers
 * - int rows: Number of rows
 * - int cols: Number of columns
 * - int **start: Pointer to pointer to starting address of sequence
 * - int *max_length: Pointer to length of longest sequence
 */
void max_consecutive_integers(int (*integers)[COLS], int rows, int cols,
			      int **start, int *max_length) {
	// beginning address of integers
	int *beginning = integers[0];

	*max_length = 0;

	int *curr_start = beginning;
	int curr_length = 0;
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			if (integers[i][j] != *curr_start) {
				if (curr_length > *max_length) {
					// set new longest
					*max_length = curr_length;
					*start = curr_start;
				}

				// set to 1 because it includes the first one
				curr_length = 1;
				curr_start = beginning + i * rows + j;
				continue;
			}

			++curr_length;
		}
	}

	// catch the end
	if (curr_length > *max_length) {
		*max_length = curr_length;
		*start = curr_start;
	}
}

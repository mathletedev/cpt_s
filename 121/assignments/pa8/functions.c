#include "headers.h"

int my_strlen(char *string) {
	int res = 0;
	// keep increasing res until null terminator is found
	while (*(string + ++res) != '\0')
		;

	return res;
}

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

int is_palindrome(char *string, int length) {
	if (length <= 1)
		return 1;
	if (string[0] == string[length - 1])
		// move left and right bounds closer
		return is_palindrome(string + 1, length - 2);
	return 0;
}

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

#ifndef HEADERS_H
#define HEADERS_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// largest ASCII value
#define ASCII_MAX 255
#define COLS 5

#define NEWLINE printf("\n")

typedef struct occurences {
	int num_occurences;
	double frequency;
} Occurences;

// util functions
int my_strlen(char *string);

char *my_str_n_cat(char *dest, char *src, int n);
int binary_search(int *arr, int n, int target);
int is_palindrome(char *string, int length);
unsigned int sum_primes(unsigned int n);
int maximum_occurences(char *string, Occurences *occurences, int *max,
		       char *max_char);
void max_consecutive_integers(int integers[][5], int rows, int cols,
			      int **start, int *max_length);

#endif

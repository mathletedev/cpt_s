#ifndef HEADERS_H
#define HEADERS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 50
#define MAX_COLS 100

typedef struct movie_record {
	char title[MAX_COLS];
	int year;
} MovieRecord;

#endif

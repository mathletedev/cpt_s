#ifndef TYPES_H
#define TYPES_H

#ifdef _WIN_32
#include <windows.h>
#define _sleep(x) Sleep(x * 1000)
#else
#include <unistd.h>
#define _sleep(x) sleep(x)
#endif

#define NEWLINE printf("\n")

#define MAX_STR 100

typedef struct duration_t {
	int minutes;
	int seconds;
} Duration;

typedef struct record_t {
	char artist[MAX_STR];
	char album[MAX_STR];
	char title[MAX_STR];
	char genre[MAX_STR];
	Duration length;
	int plays;
	int rating;
} Record;

#endif

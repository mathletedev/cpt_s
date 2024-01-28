#ifndef TYPES_H
#define TYPES_H

#define NEWLINE printf("\n")

typedef struct duration_t {
	int minutes;
	int seconds;
} Duration;

typedef struct record_t {
	char artist[100];
	char album[100];
	char title[100];
	char genre[100];
	Duration length;
	int plays;
	int rating;
} Record;

#endif

/*
 * Programming Assignment 1
 * Author: Neal Wang
 * Lab: 05
 * Due date: 2024-01-24
 * Various definitions
 */

#ifndef HEADERS_H
#define HEADERS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 24 hours of data, 60 mins per hour
#define NUM_POINTS 24 * 60
#define MAX_LINE 100
#define INVALID 1e9

typedef enum sleep { NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3 } Sleep;

typedef struct fitbit_data {
	char patient[10];
	char minute[9];
	double calories;
	double distance;
	unsigned int floors;
	unsigned int heart_rate;
	unsigned int steps;
	Sleep sleep_level;
} FitbitData;

typedef struct node {
	char minute[9];
	struct node *next;
} Node;

char *my_strtok(char *str, const char delim);

int is_empty(char *str);

void insert_end(Node **head, char *minute);
void clean(Node **head);
void write_list(FILE *outfile, Node *head);

void write_data(FitbitData *data);

#endif

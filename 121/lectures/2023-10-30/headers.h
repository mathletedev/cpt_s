#ifndef HEADERS_H
#define HEADERS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 300
#define MAX_COLS 100

typedef struct StudentRecord {
	int id;
	char last_name[30];
	char first_name[30];
	double gpa;
} StudentRecord;

StudentRecord init_student_record(void);
void init_student_record_ptr(StudentRecord *sr);
void write_students(StudentRecord *arr, size_t size);

#define CONNECT4_ROWS 6
#define CONNECT4_COLS 7

typedef struct Position {
	int row;
	int col;
} Position;

typedef struct Token {
	char player;
} Token;

typedef struct Cell {
	Token token;
	Position position;
} Cell;

typedef struct Board {
	Cell cells[CONNECT4_ROWS][CONNECT4_COLS];
	int rows;
	int cols;
} Board;

#endif

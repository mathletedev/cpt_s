/*
 * Name: Neal Wang
 * Due Date: 2023-10-25
 * Lecture: 02
 * Lab: 25
 * Assignment: PA 3
 * Description: Header file for io.c
 */

#ifndef IO_H
#define IO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ANSI colour codes for cool text
// https://stackoverflow.com/questions/3219393/stdlib-and-colored-output-in-c
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"

#define NEWLINE printf("\n")

void clear(void);
void wait_for_keypress(void);

void write_question(char *question);
void write_prompt(char *question);
void write_option(char label, char *description);
void write_combination(char label, char *description, int points);
int read_option(char *labels, char *input_ptr);
void warn_invalid(void);

#endif

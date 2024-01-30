/*
 * Programming Assignment 2
 * Author: Neal Wang
 * Lab: 05
 * Due date: 2024-01-31
 * Utility functions
 */

#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>

void clear(void);
void suspend(void);
void consume_input(void);
char *next_tok(char *str, char delim);

#endif

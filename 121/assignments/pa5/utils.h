/*
 * Name: Neal Wang
 * Due Date: 2023-10-25
 * Lecture: 02
 * Lab: 25
 * Assignment: PA 3
 * Description: Header file for utils.c
 */

#ifndef UTILS_H
#define UTILS_H

#include "io.h"

#define NUM_DICE 5
#define NUM_COMBINATIONS 13

void yahtzee(void);
void write_menu(void);
void write_rules(void);
void roll_dice(int *dice);
int combination_to_index(char combination);
int sum_score(int *arr);

#endif

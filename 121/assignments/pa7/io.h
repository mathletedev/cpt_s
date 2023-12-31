/*
 * Name: Neal Wang
 * Due Date: 2023-11-29
 * Lecture: 02
 * Lab: 25
 * Assignment: PA 7
 * Description: Input/output functions
 */

#ifndef IO_H
#define IO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "constants.h"
#include "types.h"

void wait_for_enter(void);
void clear(void);
void consume_input(void);

void warn(char *message);

int menu(void);
void rules(void);

void write_hand(Hand *hand, int visible, int show_ids);

#endif

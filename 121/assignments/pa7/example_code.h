/*
 * Name: Neal Wang
 * Due Date: 2023-11-29
 * Lecture: 02
 * Lab: 25
 * Assignment: PA 7
 * Description: Example code supplied by Dietel & Dietel
 */

#ifndef EXAMPLE_CODE_H
#define EXAMPLE_CODE_H

#include <stdio.h>
#include <stdlib.h>

#include "types.h"

void shuffle(int *deck);
void deal(Hand *hand, int *deck, int *seed, int mask);

#endif

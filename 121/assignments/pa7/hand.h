/*
 * Name: Neal Wang
 * Due Date: 2023-11-29
 * Lecture: 02
 * Lab: 25
 * Assignment: PA 7
 * Description: Various poker hand utility functions
 */

#ifndef HAND_H
#define HAND_H

#include "constants.h"
#include "types.h"

#include <stdio.h>

void sort(int *frequency, int *res);
int qual_x(int *frequency, int x, int *max);

int qual_pair(int *frequency, int *max);
int qual_two_pairs(int *frequency);
int qual_three(int *frequency, int *max);
int qual_four(int *frequency, int *max);
int qual_full(int *frequency);
int qual_flush(int *frequency, Hand *hand, int *max);
int qual_straight(int *frequency);

int qual(Hand *hand);

int winner(Hand *dealer_hand, Hand *player_hand);

int ai_x(Hand *hand, int *frequency, int x);
int ai(Hand *hand);

#endif

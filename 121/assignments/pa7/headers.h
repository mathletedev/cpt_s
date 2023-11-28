/*
 * Name: Neal Wang
 * Due Date: 2023-11-29
 * Lecture: 02
 * Lab: 25
 * Assignment: PA 7
 * Description: Interactive Five-card draw game
 */

#ifndef HEADERS_H
#define HEADERS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// sleep function for AI "thinking"
// https://www.geeksforgeeks.org/sleep-function-in-c
#ifdef _WIN_32
#include <Windows.h>
#define sleep Sleep
#else
#include <unistd.h>
#endif

#include "example_code.h"
#include "hand.h"
#include "io.h"
#include "types.h"

#endif

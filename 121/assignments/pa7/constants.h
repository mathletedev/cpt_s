/*
 * Name: Neal Wang
 * Due Date: 2023-11-29
 * Lecture: 02
 * Lab: 25
 * Assignment: PA 7
 * Description: #define constants
 */

#ifndef CONSTANTS_H
#define CONSTANTS_H

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

#define NUM_CARDS 5
#define NUM_FACES 13

// max length of message
#define MESSAGE_SIZE 100

// weight of a better quality hand
#define WEIGHT 10000

#endif

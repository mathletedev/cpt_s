#ifndef HEADERS_H
#define HEADERS_H

#include "globals.h"
#include "linked_list.h"
#include <stdio.h>

#define MAX_LINE 1000

// utility functions
void clear(void);
void suspend(void);
void consume_input(void);

// commands
int main_menu(void);
void load(Node **head, FILE *stream);
void store(Node *head, FILE *stream);
void display(Node *head, char *artist);

#endif

/*
 * Programming Assignment 2
 * Author: Neal Wang
 * Lab: 05
 * Due date: 2024-01-31
 * Individual commands
 */

#ifndef COMMANDS_H
#define COMMANDS_H

#include "globals.h"
#include "linked_list.h"
#include "utils.h"
#include <stdio.h>

#define MAX_LINE 1000

// commands
int main_menu(void);
void load(Node **head);
void store(Node *head);
void display(Node *head);
void edit(Node *head);
void rate(Node *head);
void play(Node *head);

#endif

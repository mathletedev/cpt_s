/*
 * Programming Assignment 3
 * Author: Neal Wang
 * Lab: 05
 * Due date: 2024-02-09
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
void insert(Node **head);
// delete() already exists
void _delete(Node **head);
void sort(Node *head);

#endif

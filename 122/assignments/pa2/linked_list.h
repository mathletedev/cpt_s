/*
 * Programming Assignment 2
 * Author: Neal Wang
 * Lab: 05
 * Due date: 2024-01-31
 * Implementation of linked list data structure
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "globals.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_t {
	Record data;
	struct node_t *prev;
	struct node_t *next;
} Node;

Node *create_node(Record data);
int insert_front(Node **head, Record data);
int print_list(Node *head);
void free_list(Node **head);
Node *find_by_artist(Node *head, char *artist);
Node *find_one_by_title(Node *head, char *title);

#endif

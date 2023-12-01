#ifndef HEADERS_H
#define HEADERS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
} Node;

Node *create_node(int data);
int insert_front(Node **head, int data);

#endif

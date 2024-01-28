#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "globals.h"
#include <stdlib.h>
#include <string.h>

typedef struct node_t {
	Record data;
	struct node_t *prev;
	struct node_t *next;
} Node;

Node *create_node(Record data);
Node *insert_front(Node **head, Record data);

#endif

#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

typedef struct data_t {
	char letter;
} Data;

typedef struct node_t {
	Data data;
	struct node_t *next;
} Node;

typedef struct stack_t {
	Node *top;
} Stack;

Node *create_node(Data data);
int is_empty(const Stack *stack);
Data peek(const Stack *stack);
int push(Stack *stack, Data data);
int pop(Stack *stack);

#endif

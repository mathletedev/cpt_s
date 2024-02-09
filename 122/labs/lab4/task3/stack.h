#pragma once

#include "stdlib.h"

typedef struct node_t {
	int data;
	struct node_t *next;
} Node;

typedef struct stack_t {
	Node *top;
} Stack;

int is_empty(Stack *stack);
int push(Stack *stack, int data);
void pop(Stack *stack);
double peek(Stack *stack);

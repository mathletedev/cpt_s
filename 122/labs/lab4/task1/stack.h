#pragma once

#include "stdlib.h"

typedef struct stack_node_t {
	double data;
	struct stack_node_t *next;
} StackNode;

typedef struct stack_t {
	StackNode *top;
} Stack;

int is_empty(Stack *stack);
int push(Stack *stack, double data);
void pop(Stack *stack);
double peek(Stack *stack);

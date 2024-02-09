#include "stack.h"

int is_empty(Stack *stack) {
	return stack->top == NULL;
}

int push(Stack *stack, double data) {
	StackNode *node = malloc(sizeof(StackNode));
	if (node == NULL) return 0;

	node->data = data;

	node->next = stack->top;
	stack->top = node;

	return 1;
}

void pop(Stack *stack) {
	StackNode *next = stack->top->next;
	free(stack->top);

	stack->top = next;
}

double peek(Stack *stack) {
	return stack->top->data;
}

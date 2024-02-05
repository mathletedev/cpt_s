#include "stack.h"

Node *create_node(Data data) {
	Node *node = malloc(sizeof(Node));
	if (node == NULL) return NULL;

	node->data = data;
	node->next = NULL;

	return node;
}

int is_empty(const Stack *stack) {
	return stack->top == NULL;
}

Data peek(const Stack *stack) {
	return stack->top->data;
}

int push(Stack *stack, Data data) {
	Node *node = create_node(data);
	if (node == NULL) return 0;

	node->next = stack->top;
	stack->top = node;

	return 1;
}

int pop(Stack *stack) {
	Node *top = stack->top;
	if (top == NULL) return 0;

	stack->top = top->next;
	free(top);

	return 1;
}

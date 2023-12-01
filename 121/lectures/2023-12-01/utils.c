#include "headers.h"

Node *create_node(int data) {
	Node *node = malloc(sizeof(Node));

	node->data = data;
	node->next = NULL;

	return node;
}

int insert_front(Node **head, int data) {
	Node *node = create_node(data);

	if (node == NULL)
		return 0;

	if (*head == NULL)
		*head = node;
	else {
		node->next = *head;
		*head = node;
	}

	return 1;
}

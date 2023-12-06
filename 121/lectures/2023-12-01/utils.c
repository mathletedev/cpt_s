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

	if (*head == NULL) {
		*head = node;
		return 1;
	}

	node->next = *head;
	*head = node;
	return 1;
}

int insert(Node **head, int data) {
	Node *node = create_node(data);

	if (node == NULL)
		return 0;

	Node *curr = *head;
	Node *prev = NULL;

	while (curr != NULL && curr->data < data) {
		prev = curr;
		curr = curr->next;
	}

	node->next = curr;
	if (prev == NULL)
		*head = node;
	else
		prev->next = node;

	return 1;
}

void write_list(Node *head) {
	if (head == NULL)
		return;

	printf("--> %d ", head->data);
	write_list(head->next);
}

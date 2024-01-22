#include "headers.h"

void insert_front(Node **head, MovieRecord data) {
	Node *node = malloc(sizeof(Node));
	// failed to allocate space on the heap
	if (node == NULL)
		return;

	node->data.year = data.year;
	strcpy(node->data.title, data.title);

	node->next = *head;
	*head = node;
}

MovieRecord remove_front(Node **head) {}

void print_list(Node *head) {
	while (head != NULL) {
		printf("%s | %d\n", head->data.title, head->data.year);

		head = head->next;
	}
}

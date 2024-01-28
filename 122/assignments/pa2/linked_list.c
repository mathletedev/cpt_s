#include "linked_list.h"

Node *create_node(Record data) {
	Node *node = malloc(sizeof(Node));
	if (node == NULL)
		return NULL;

	strcpy(node->data.artist, data.artist);
	strcpy(node->data.album, data.album);
	strcpy(node->data.title, data.title);
	strcpy(node->data.genre, data.genre);
	node->data.length = data.length;
	node->data.plays = data.plays;
	node->data.rating = data.rating;

	return node;
}

Node *insert_front(Node **head, Record data) {
	Node *node = create_node(data);
	if (node == NULL)
		return NULL;

	node->next = *head;
	if (*head != NULL)
		(*head)->prev = node;
	*head = node;

	return node;
}

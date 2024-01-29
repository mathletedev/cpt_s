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

// recursively frees nodes of list
void free_list(Node **head) {
	if (*head == NULL)
		return;

	free_list(&(*head)->next);
	free(*head);
	*head = NULL;
}

// returns a linked list of all nodes that match artist
Node *find_by_artist(Node *head, char *artist) {
	Node *res = NULL;

	for (; head != NULL; head = head->next) {
		if (strcmp(head->data.artist, artist) == 0)
			insert_front(&res, head->data);
	}

	return res;
}

// returns a linked list of all nodes that match artist
Node *find_one_by_title(Node *head, char *title) {
	for (; head != NULL; head = head->next) {
		if (strcmp(head->data.title, title) == 0)
			return head;
	}

	return NULL;
}

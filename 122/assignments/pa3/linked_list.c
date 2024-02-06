#include "linked_list.h"

Node *create_node(Record data) {
	// validate data
	if (data.length.minutes < 0 || data.length.seconds < 0 ||
	    data.length.seconds > 59 || data.plays < 0 || data.rating < 1 ||
	    data.rating > 5)
		return NULL;

	Node *node = malloc(sizeof(Node));
	if (node == NULL) return NULL;

	strcpy(node->data.artist, data.artist);
	strcpy(node->data.album, data.album);
	strcpy(node->data.title, data.title);
	strcpy(node->data.genre, data.genre);
	node->data.length = data.length;
	node->data.plays = data.plays;
	node->data.rating = data.rating;

	node->next = NULL;
	node->prev = NULL;

	return node;
}

// finds the length of a linked list
int get_length(Node *head) {
	if (head == NULL) return 0;

	int i = 1;
	for (Node *curr = head->next; curr != head; curr = curr->next)
		++i;

	return i;
}

// insert node into circular doubly linked list
int insert_front(Node **head, Record data) {
	Node *node = create_node(data);
	if (node == NULL) return 0;

	if (*head == NULL) {
		// circular links
		node->next = node;
		node->prev = node;
		*head = node;
		return 1;
	}

	node->next = *head;
	node->prev = (*head)->prev;
	(*head)->prev->next = node;
	(*head)->prev = node;

	*head = node;

	return 1;
}

int delete_node(Node **head, char *title) {
	if (strcmp((*head)->data.title, title) == 0) {
		Node *next = (*head)->next;
		free(*head);
		*head = next;

		return 1;
	}

	Node *curr = *head;
	while (curr != NULL && strcmp(curr->data.title, title) != 0)
		curr = curr->next;

	if (curr == NULL) return 0;

	curr->prev->next = curr->next;
	if (curr->next != NULL) curr->next->prev = curr->prev;
	free(curr);

	return 1;
}

// prints records, returns number of records printed
int print_list(Node *head) {
	int i = 0;
	for (Node *curr = head; i < get_length(head); curr = curr->next, ++i)
		printf(
		    "%d. %s | %s | %s | %s | %d:%d | %d plays | %d/5 rating\n",
		    i + 1, curr->data.artist, curr->data.album,
		    curr->data.title, curr->data.genre,
		    curr->data.length.minutes, curr->data.length.seconds,
		    curr->data.plays, curr->data.rating);

	return i - 1;
}

// recursively frees nodes of list
void free_list(Node **head) {
	if (*head == NULL) return;

	// break the link
	(*head)->prev->next = NULL;

	if (*head != NULL) free_list(&(*head)->next);
	free(*head);

	*head = NULL;
}

// returns a linked list of all nodes that match artist
Node *find_by_artist(Node *head, char *artist) {
	Node *res = NULL;

	int i = 0;
	for (Node *curr = head; i < get_length(head); curr = curr->next, ++i) {
		if (strcmp(curr->data.artist, artist) == 0)
			insert_front(&res, curr->data);
	}

	return res;
}

// returns a linked list of all nodes that match artist
Node *find_one_by_title(Node *head, char *title) {
	int i = 0;
	for (Node *curr = head; i < get_length(head); curr = curr->next, ++i) {
		if (strcmp(curr->data.title, title) == 0) return curr;
	}

	return NULL;
}

// sorts a linked list by given method
void sort_list(Node *head, Sort method) {
	int length = get_length(head);

	for (int i = 0; i < length - 1; ++i) {
		// keep track of nodes to swap
		Node *initial = NULL;
		Node *best = NULL;
		int j = 0;
		for (Node *curr = head; j < get_length(head);
		     curr = curr->next, ++j) {
			// continue if inside sorted region
			if (j < i) continue;

			// first unsorted
			if (initial == NULL) {
				best = initial = curr;
				continue;
			}

			// check if curr node is better candidate
			int better;
			switch (method) {
			case ARTIST:
				better = strcmp(curr->data.artist,
						best->data.artist) < 0;
				break;
			case ALBUM:
				better = strcmp(curr->data.album,
						best->data.album) < 0;
				break;
			case RATING:
				better = curr->data.rating < best->data.rating;
				break;
			case PLAYS:
				better = curr->data.plays > best->data.plays;
				break;
			}

			if (better) best = curr;
		}

		// swap best and initial
		Record tmp = initial->data;
		initial->data = best->data;
		best->data = tmp;
	}
}

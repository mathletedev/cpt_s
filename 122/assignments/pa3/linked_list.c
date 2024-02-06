#include "linked_list.h"

Node *create_node(Record data) {
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
	int i = 0;
	for (; head != NULL; head = head->next)
		++i;

	return i;
}

int insert_front(Node **head, Record data) {
	Node *node = create_node(data);
	if (node == NULL) return 0;

	node->next = *head;
	if (*head != NULL) (*head)->prev = node;
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
	int i = 1;
	for (; head != NULL; head = head->next, ++i)
		printf(
		    "%d. %s | %s | %s | %s | %d:%d | %d plays | %d/5 rating\n",
		    i, head->data.artist, head->data.album, head->data.title,
		    head->data.genre, head->data.length.minutes,
		    head->data.length.seconds, head->data.plays,
		    head->data.rating);

	return i - 1;
}

// recursively frees nodes of list
void free_list(Node **head) {
	if (*head == NULL) return;

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
		if (strcmp(head->data.title, title) == 0) return head;
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
		for (Node *curr = head; curr != NULL; curr = curr->next, ++j) {
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

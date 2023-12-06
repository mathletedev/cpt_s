#include "headers.h"

int main(void) {
	Node *head = NULL;

	insert(&head, 4444);
	insert(&head, 3333);
	insert(&head, 2222);
	insert(&head, 1111);

	write_list(head);

	return 0;
}

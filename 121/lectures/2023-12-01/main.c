#include "headers.h"

int main(void) {
	Node *head = NULL;

	int success = insert_front(&head, 4);
	success = insert_front(&head, 8);

	printf("1) id: %d, link: %p\n", head->data, head->next);
	printf("2) id: %d, link: %p\n", head->next->data, head->next->next);

	return 0;
}

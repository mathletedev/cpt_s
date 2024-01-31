#include "tests.h"

void test_delete_node(void) {
	Contact c1 = {"A", "", "", ""};
	Contact c2 = {"B", "", "", ""};
	Contact c3 = {"C", "", "", ""};
	Contact c4 = {"D", "", "", ""};

	Node *head = NULL;
	insert_ordered(&head, c1);
	insert_ordered(&head, c2);
	insert_ordered(&head, c3);

	// test 1
	if (delete_node(&head, c4) == FALSE)
		puts("test 1 passed");
	else
		puts("test 1 failed");

	// test 2
	int passed2 = 1;
	delete_node(&head, c3);
	for (Node *curr = head; curr != NULL; curr = curr->next) {
		if (strcmp(curr->data.name, c3.name) == 0)
			passed2 = 0;
	}
	if (passed2)
		puts("test 2 passed");
	else
		puts("test 2 failed");

	// test 3
	int passed3 = 1;
	delete_node(&head, c1);
	for (Node *curr = head; curr != NULL; curr = curr->next) {
		if (strcmp(curr->data.name, c1.name) == 0)
			passed3 = 0;
	}
	if (passed3)
		puts("test 3 passed");
	else
		puts("test 3 failed");
}

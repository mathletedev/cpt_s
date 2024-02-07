#include "test.h"

void test_insert(void) {
	puts("---- test_insert() ----");

	Node *head = NULL;

	// clang-format off
	Record data = {
	    "Perry, Katy",
			"Witness",
			"Chained to the Rhythm",
			"Pop",
			{4, 36},
			-1,
			6
	};
	// clang-format on

	if (insert_front(&head, data) == 0 && head == NULL)
		puts("Test passed");
	else
		puts("Test failed");

	free_list(&head);
}

void test_delete(void) {
	puts("---- test_delete() ----");

	Node *head = NULL;

	// clang-format off
	Record data = {
	    "Perry, Katy",
			"Witness",
			"Chained to the Rhythm",
			"Pop",
			{4, 36},
			3,
			5
	};
	// clang-format on

	insert_front(&head, data);

	delete_node(&head, "Chained to the Rhythm");

	if (head == NULL)
		puts("Test passed");
	else
		puts("Test failed");

	free_list(&head);
}

void test_shuffle(void) {
	puts("---- test_delete() ----");

	Node *head = NULL;

	// clang-format off
	Record data1 = {
	    "Swift, Taylor",
			"1989",
			"Shake it Off",
			"Pop",
			{3, 35},
			12,
			3
	};
	Record data2 = {
	    "Drake",
			"NOTHING WAS THE SAME",
			"Own it",
			"Rap",
			{3, 23},
			3,
			3
	};
	Record data3 = {
	    "Drake",
			"YOU WELCOME",
			"The Motto",
			"Rap",
			{4, 13},
			7,
			4
	};
	// clang-format on

	insert_front(&head, data3);
	insert_front(&head, data2);
	insert_front(&head, data1);

	int order[] = {3, 1, 2};

	puts("Expected output:");
	puts("The Motto -> Shake it Off -> Own it ->");

	puts("Actual output:");
	shuffle_play(head, order, 3, 1);

	free_list(&head);
}

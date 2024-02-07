/*
 * Programming Assignment 2
 * Author: Neal Wang
 * Lab: 05
 * Due date: 2024-01-31
 * Digital music manager
 */

#include "commands.h"
#include "test.h"

// uncomment this line to test code
// #define TESTING

#ifdef TESTING
int main(void) {
	test_insert();
	NEWLINE;
	test_delete();
	NEWLINE;
	test_shuffle();
	NEWLINE;

	return 0;
}
#else
int main(void) {
	srand(time(NULL));

	Node *head = NULL;

	while (1) {
		clear();

		int command = main_menu();

		clear();

		// exit command
		if (command == 11) {
			store(head);
			break;
		}

		switch (command) {
		case 1:
			load(&head);
			break;
		case 2:
			store(head);
			break;
		case 3:
			display(head);
			break;
		case 4:
			insert(&head);
			break;
		case 5:
			_delete(&head);
			break;
		case 6:
			edit(head);
			break;
		case 7:
			sort(head);
			break;
		case 8:
			rate(head);
			break;
		case 9:
			play(head);
			break;
		case 10: {
			int n = get_length(head);

			// initialise dynamic length array with numbers 1 - N
			int *order = malloc(sizeof(int) * n);
			randomise(order, n);

			shuffle_play(head, order, n, 0);

			// remember to free memory
			free(order);
			break;
		}
		}

		NEWLINE;
		suspend();
	}

	free_list(&head);

	return 0;
}
#endif

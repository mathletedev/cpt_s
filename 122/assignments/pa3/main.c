/*
 * Programming Assignment 2
 * Author: Neal Wang
 * Lab: 05
 * Due date: 2024-01-31
 * Digital music manager
 */

#include "commands.h"

int main(void) {
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
		}

		NEWLINE;
		suspend();
	}

	free_list(&head);

	return 0;
}

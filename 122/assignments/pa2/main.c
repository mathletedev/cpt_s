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
		case 6:
			edit(head);
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

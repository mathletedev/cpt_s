#include "headers.h"

int main(void) {
	FILE *stream = fopen("musicPlayList.csv", "rw");
	if (stream == NULL) {
		puts("Failed to open musicPlayList.csv");
		return 1;
	}

	Node *head = NULL;

	while (1) {
		clear();

		int command = main_menu();

		clear();

		switch (command) {
		case 1:
			load(&head, stream);
			break;
		case 2:
			store(head, stream);
			break;
		case 3:
			display(head, NULL);
			break;
		}

		suspend();
	}

	return 0;
}

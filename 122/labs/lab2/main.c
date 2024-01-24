#include "headers.h"

int main(void) {
	FILE *infile = fopen("contacts.csv", "r");
	if (infile == NULL) {
		puts("Failed to open contacts.csv");
		return 1;
	}
	FILE *outfile = fopen("saved.csv", "w");
	if (infile == NULL) {
		puts("Failed to open contacts.csv");
		return 1;
	}

	Node *head = NULL;

	load_contacts(infile, &head);

	Contact target = {"Wang Neal", "", "", ""};
	delete_node(&head, target);

	Contact data = {"Liu Charles", "12345", "hello", "Professor"};
	edit_node(&head, data);

	print_contacts(head);

	store_contacts(outfile, head);

	fclose(infile);
	fclose(outfile);

	return 0;
}

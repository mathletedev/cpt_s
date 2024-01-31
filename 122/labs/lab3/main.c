#include "headers.h"
#include "tests.h"

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

	print_contacts(head);

	fclose(infile);
	fclose(outfile);

	test_delete_node();

	return 0;
}

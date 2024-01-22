/*
 * Programming Assignment 1
 * Author: Neal Wang
 * Lab: 05
 * Due date: 2024-01-24
 * Utility functions
 */

#include "headers.h"

// finds substrings separated by delim
// does NOT skip consecutive delimiters
// code copied from lab 1
char *my_strtok(char *str, const char delim) {
	static char *p_token;
	if (str != NULL)
		p_token = str;

	char *beginning = p_token;

	while (*p_token != delim) {
		++p_token;
		if (*p_token == '\0')
			break;
	}
	*p_token = '\0';
	++p_token;

	return beginning;
}

// checks if a string is empty ("")
int is_empty(char *str) { return strcmp(str, "") ? 0 : 1; }

// inserts a node at the end of a linked list
void insert_end(Node **head, char *minute) {
	// at the end
	if (*head == NULL) {
		Node *new = malloc(sizeof(Node));
		strcpy(new->minute, minute);
		new->next = NULL;

		*head = new;
		return;
	}

	// recurse to next node
	insert_end(&((*head)->next), minute);
}

// recursively de-allocates a linked list
void clean(Node **head) {
	if (*head == NULL)
		return;

	clean(&((*head)->next));
	free(*head);
	*head = NULL;
}

// writes a linked list to outfile separated by "|"
void write_list(FILE *outfile, Node *head) {
	if (head == NULL)
		return;

	fprintf(outfile, "%s", head->minute);
	if (head->next != NULL) {
		fprintf(outfile, "|");
		write_list(outfile, head->next);
	}
}

// formats and writes data to stdout
void write_data(FitbitData *data) {
	printf("%s,%s,%lf,%lf,%d,%d,%d,%d", data->patient, data->minute,
	       data->calories, data->distance, data->floors, data->heart_rate,
	       data->steps, data->sleep_level);
}

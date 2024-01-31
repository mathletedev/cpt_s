#include "headers.h"

Node *create_node(Contact data) {
	Node *node = malloc(sizeof(Node));
	if (node == NULL)
		return NULL;

	node->next = NULL;
	node->prev = NULL;

	strcpy(node->data.name, data.name);
	strcpy(node->data.phone, data.phone);
	strcpy(node->data.email, data.email);
	strcpy(node->data.title, data.title);

	return node;
}

Boolean insert_ordered(Node **head, Contact data) {
	printf("%s\n", data.name);
	Node *node = create_node(data);
	if (node == NULL)
		return FALSE;

	if (*head == NULL) {
		*head = node;
		return TRUE;
	}

	if (strcmp(data.name, (*head)->data.name) < 0) {
		node->next = *head;
		(*head)->prev = node;
		*head = node;
		return TRUE;
	}

	Node *curr = *head;

	while (curr->next != NULL && strcmp(data.name, curr->data.name) > 0)
		curr = curr->next;

	if (curr->next == NULL) {
		node->prev = curr;
		curr->next = node;
		return TRUE;
	}

	node->next = curr;
	node->prev = curr->prev;
	curr->prev->next = node;
	curr->prev = node;

	return TRUE;
}

Boolean delete_node(Node **head, Contact target) {
	if (*head == NULL)
		return FALSE;

	if (strcmp((*head)->data.name, target.name) == 0) {
		Node *next = (*head)->next;

		next->prev = NULL;
		free(*head);

		*head = next;

		return TRUE;
	}

	Node *curr = *head;

	while (curr != NULL && strcmp(target.name, curr->data.name) != 0)
		curr = curr->next;

	if (curr == NULL)
		return FALSE;

	curr->prev->next = curr->next;
	free(curr);

	return TRUE;
}

Boolean edit_node(Node **head, Contact data) {
	if (*head == NULL)
		return FALSE;

	if (strcmp((*head)->data.name, data.name) == 0) {
		strcpy((*head)->data.phone, data.phone);
		strcpy((*head)->data.email, data.email);
		strcpy((*head)->data.title, data.title);

		return TRUE;
	}

	Node *curr = (*head)->next;

	while (curr != NULL && strcmp(data.name, curr->data.name) != 0)
		curr = curr->next;

	if (curr == NULL)
		return FALSE;

	strcpy(curr->data.phone, data.phone);
	strcpy(curr->data.email, data.email);
	strcpy(curr->data.title, data.title);

	return TRUE;
}

Boolean load_contacts(FILE *infile, Node **head) {
	char line[MAX_LINE];

	while (fgets(line, MAX_LINE, infile) != NULL) {
		Contact contact;
		strcpy(contact.name, strtok(line, ","));
		strcpy(contact.phone, strtok(NULL, ","));
		strcpy(contact.email, strtok(NULL, ","));
		strcpy(contact.title, strtok(NULL, "\n"));

		insert_ordered(head, contact);
	}

	return TRUE;
}

Boolean store_contacts(FILE *outfile, Node *head) {
	for (; head != NULL; head = head->next)
		fprintf(outfile, "%s,%s,%s,%s\n", head->data.name,
			head->data.phone, head->data.email, head->data.title);

	return TRUE;
}

void print_contacts(Node *head) {
	for (; head != NULL; head = head->next)
		printf("Name: %s, Phone: %s, Email: %s, Title: %s\n",
		       head->data.name, head->data.phone, head->data.email,
		       head->data.title);
}

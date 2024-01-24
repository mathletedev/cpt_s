#ifndef HEADERS_H
#define HEADERS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 100

typedef enum boolean { FALSE, TRUE } Boolean;

typedef struct contact {
	char name[50];
	char phone[12];
	char email[50];
	char title[20];
} Contact;

typedef struct node {
	Contact data;
	struct node *next;
} Node;

Node *create_node(Contact data);
Boolean insert_ordered(Node **head, Contact data);
Boolean delete_node(Node **head, Contact target);
Boolean edit_node(Node **head, Contact data);
Boolean load_contacts(FILE *infile, Node **head);
Boolean store_contacts(FILE *outfile, Node *head);
void print_contacts(Node *head);

#endif

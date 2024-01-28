#include "headers.h"

// clears the console
void clear(void) {
	// https://stackoverflow.com/a/36253316
#ifdef _WIN_32
	system("cls");
#else
	system("clear");
#endif
}

// waits for a key to be pressed
void suspend(void) {
	printf("Press any key to continue...");
	char c;
	scanf("%c", &c);
}

// consumes remaining scanf()
void consume_input(void) {
	for (char c; c != '\n'; scanf("%c", &c))
		;
}

// displays a main menu, returns a validated choice
int main_menu(void) {
	puts("(1)  load");
	puts("(2)  store");
	puts("(3)  display");
	puts("(4)  insert");
	puts("(5)  delete");
	puts("(6)  edit");
	puts("(7)  sort");
	puts("(8)  rate");
	puts("(9)  play");
	puts("(10) shuffle");
	puts("(11) exit");

	int choice;
	int num_read = -1;
	do {
		if (num_read != -1)
			puts("Invalid input");

		NEWLINE;
		printf("> ");

		num_read = scanf("%d", &choice);
		consume_input();
	} while (num_read != 1 || choice < 1 || choice > 11);

	return choice;
}

// reads and inserts records to the front of a linked list
void load(Node **head, FILE *stream) {
	int num = 0;
	for (char line[MAX_LINE]; fgets(line, MAX_LINE, stream) != NULL;
	     ++num) {
		Record record;
		// skip to end quote
		if (line[0] == '"')
			strcpy(record.artist, strtok(line + 1, "\""));
		else
			strcpy(record.artist, strtok(line, ","));

		strcpy(record.album, strtok(NULL, ","));
		strcpy(record.title, strtok(NULL, ","));
		strcpy(record.genre, strtok(NULL, ","));
		record.length.minutes = atoi(strtok(NULL, ":"));
		record.length.seconds = atoi(strtok(NULL, ","));
		record.plays = atoi(strtok(NULL, ","));
		record.rating = atoi(strtok(NULL, "\n"));

		insert_front(head, record);
	}

	printf("Successfully loaded %d records\n", num);
}

void store(Node *head, FILE *stream) {
	int num = 0;
	for (; head != NULL; head = head->next) {
		// add quote for commas
		if (strchr(head->data.artist, ','))
			fprintf(stream, "\"");
		fprintf(stream, "%s", head->data.artist);
		if (strchr(head->data.artist, ','))
			fprintf(stream, "\"");

		fprintf(stream, "%s,%s,%s,%d:%d,%d,%d\n", head->data.album,
			head->data.title, head->data.genre,
			head->data.length.minutes, head->data.length.seconds,
			head->data.plays, head->data.rating);

		++num;
	}

	printf("Successfully stored %d records\n", num);
}

// displays all records in linked list
void display(Node *head, char *artist) {
	for (; head != NULL; head = head->next) {
		// check if artist matches
		if (artist != NULL && strcmp(head->data.artist, artist) != 0)
			continue;
		puts(head->data.title);
	}
}

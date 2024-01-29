#include "commands.h"

// displays a main menu, returns a validated choice
int main_menu(void) {
	puts("Digital Music Manager");
	NEWLINE;
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
	NEWLINE;
	puts("Select a command:");

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

// reads and inserts records from musicPlayList.csv to front of linked list
void load(Node **head) {
	FILE *stream = fopen("musicPlayList.csv", "r");
	if (stream == NULL) {
		puts("Failed to open musicPlayList.csv");
		return;
	}

	int num = 0;
	for (char line[MAX_LINE]; fgets(line, MAX_LINE, stream) != NULL;
	     ++num) {
		Record record;
		strcpy(record.artist, next_tok(line, ','));
		strcpy(record.album, next_tok(NULL, ','));
		strcpy(record.title, next_tok(NULL, ','));
		strcpy(record.genre, next_tok(NULL, ','));
		record.length.minutes = atoi(next_tok(NULL, ':'));
		record.length.seconds = atoi(next_tok(NULL, ','));
		record.plays = atoi(next_tok(NULL, ','));
		record.rating = atoi(next_tok(NULL, '\n'));

		insert_front(head, record);
	}

	printf("Successfully loaded %d records\n", num);
	fclose(stream);
}

// writes all nodes in head to musicPlayList.csv
void store(Node *head) {
	FILE *stream = fopen("musicPlayList.csv", "w");
	if (stream == NULL) {
		puts("Failed to open musicPlayList.csv");
		return;
	}

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
	fclose(stream);
}

// displays all records in linked list
void display(Node *head) {
	puts("Display records by artist (enter nothing to display all):");
	NEWLINE;
	printf("> ");

	char artist[MAX_STR];
	fgets(artist, MAX_STR, stdin);
	// don't include newline
	artist[strlen(artist) - 1] = '\0';

	clear();

	int i = 1;
	for (; head != NULL; head = head->next) {
		// check if artist matches
		if (strlen(artist) > 0 &&
		    strcmp(head->data.artist, artist) != 0)
			continue;
		printf("%d. %s\n", i, head->data.title);
		++i;
	}
}

// edits a string field
void edit_str(char *str, char *label) {
	char input[MAX_STR];

	printf("%s (%s): ", label, str);
	fgets(input, MAX_STR, stdin);
	input[strlen(input) - 1] = '\0';

	if (strlen(input) > 0)
		strcpy(str, input);
}

// edits an int field
// assume input is a valid integer
void edit_int(int *x, char *label) {
	char input[MAX_STR];

	printf("%s (%d): ", label, *x);
	fgets(input, MAX_STR, stdin);
	input[strlen(input) - 1] = '\0';

	if (strlen(input) > 0)
		*x = atoi(input);
}

// prompts user for artist, gets songs, and edits one
void edit(Node **head) {
	puts("Edit records by artist:");
	NEWLINE;
	printf("> ");

	char artist[MAX_STR];
	fgets(artist, MAX_STR, stdin);
	// don't include newline
	artist[strlen(artist) - 1] = '\0';

	clear();

	Node *found = find_by_artist(*head, artist);
	if (found == NULL) {
		puts("Artist not found");
		return;
	}

	int i = 1;
	for (Node *curr = found; curr != NULL; curr = curr->next, ++i)
		printf("%d. %s\n", i, curr->data.title);

	--i;

	NEWLINE;
	puts("Select a song:");

	int choice;
	int num_read = -1;
	do {
		if (num_read != -1)
			puts("Invalid input");

		NEWLINE;
		printf("> ");

		num_read = scanf("%d", &choice);
		consume_input();
	} while (num_read != 1 || choice < 1 || choice > i);
	--choice;

	Node *curr = found;
	for (int j = 0; j < choice; ++j)
		curr = curr->next;
	Node *selected = find_one_by_title(*head, curr->data.title);

	clear();

	puts("Enter nothing to skip field");
	NEWLINE;
	edit_str(selected->data.artist, "Artist");
	edit_str(selected->data.album, "Album");
	edit_str(selected->data.title, "Title");
	edit_str(selected->data.genre, "Genre");
	edit_int(&selected->data.length.minutes, "Minutes");
	edit_int(&selected->data.length.seconds, "Seconds");
	edit_int(&selected->data.plays, "Plays");
	edit_int(&selected->data.rating, "Rating");

	free_list(&found);
}

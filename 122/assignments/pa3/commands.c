#include "commands.h"
#include "linked_list.h"

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
		if (num_read != -1) puts("Invalid input");

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

// writes str to stream, adds quotes if str contains a comma
void write_field(FILE *stream, char *str) {
	if (strchr(str, ',')) fprintf(stream, "\"");
	fprintf(stream, "%s", str);
	if (strchr(str, ',')) fprintf(stream, "\"");

	fprintf(stream, ",");
}

// writes all nodes in head to musicPlayList.csv
void store(Node *head) {
	FILE *stream = fopen("musicPlayList.csv", "w");
	if (stream == NULL) {
		puts("Failed to open musicPlayList.csv");
		return;
	}

	int i = 0;
	for (Node *curr = head; i < get_length(head); curr = curr->next, ++i) {
		Record record = curr->data;
		// add quotes for commas
		write_field(stream, curr->data.artist);
		write_field(stream, curr->data.album);
		write_field(stream, curr->data.title);
		write_field(stream, curr->data.genre);

		fprintf(stream, "%d:%d,%d,%d\n", curr->data.length.minutes,
			curr->data.length.seconds, curr->data.plays,
			curr->data.rating);
	}

	printf("Successfully stored %d records\n", i);
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

	Node *found = head;
	if (strlen(artist) > 0) {
		found = find_by_artist(head, artist);
		if (found == NULL) {
			puts("Artist not found");
			return;
		}
	}

	printf("Records by %s\n", strlen(artist) == 0 ? "all artists" : artist);
	NEWLINE;

	print_list(found);
	// make sure to free allocated space
	if (found != head) free_list(&found);
}

// reads a string field into str
void read_str(char *str, char *label, int init) {
	char input[MAX_STR];

	// init = 1 means first time
	if (init)
		printf("%s: ", label);
	else
		printf("%s (%s): ", label, str);

	fgets(input, MAX_STR, stdin);
	input[strlen(input) - 1] = '\0';

	if (strlen(input) > 0) strcpy(str, input);
}

// reads an int field into x
// assume input is a valid integer
void read_int(int *x, char *label, int init) {
	char input[MAX_STR];

	if (init)
		printf("%s: ", label);
	else
		printf("%s (%d): ", label, *x);

	fgets(input, MAX_STR, stdin);
	input[strlen(input) - 1] = '\0';

	if (strlen(input) > 0) *x = atoi(input);
}

// prompts user for artist, gets songs, and edits one
void edit(Node *head) {
	puts("Edit records by artist:");
	NEWLINE;
	printf("> ");

	char artist[MAX_STR];
	fgets(artist, MAX_STR, stdin);
	// don't include newline
	artist[strlen(artist) - 1] = '\0';

	clear();

	Node *found = find_by_artist(head, artist);
	if (found == NULL) {
		puts("Artist not found");
		return;
	}

	puts("Select a song:");
	NEWLINE;

	int i = 0;
	for (Node *curr = found; i < get_length(found); curr = curr->next, ++i)
		printf("%d. %s\n", i + 1, curr->data.title);

	int choice;
	int num_read = -1;
	do {
		if (num_read != -1) puts("Invalid input");

		NEWLINE;
		printf("> ");

		num_read = scanf("%d", &choice);
		consume_input();
	} while (num_read != 1 || choice < 1 || choice > i);
	--choice;

	Node *curr = found;
	for (int j = 0; j < choice; ++j)
		curr = curr->next;
	Node *selected = find_one_by_title(head, curr->data.title);

	clear();

	puts("Enter nothing to skip field");
	NEWLINE;
	read_str(selected->data.artist, "Artist", 0);
	read_str(selected->data.album, "Album", 0);
	read_str(selected->data.title, "Title", 0);
	read_str(selected->data.genre, "Genre", 0);
	read_int(&selected->data.length.minutes, "Minutes", 0);
	read_int(&selected->data.length.seconds, "Seconds", 0);
	read_int(&selected->data.plays, "Plays", 0);
	read_int(&selected->data.rating, "Rating", 0);

	free_list(&found);

	clear();

	puts("Successfully edited record!");
}

// rate a song by title
void rate(Node *head) {
	char title[MAX_STR];

	printf("Rate song by title: ");
	fgets(title, MAX_STR, stdin);
	title[strlen(title) - 1] = '\0';

	Node *selected = find_one_by_title(head, title);
	if (selected == NULL) {
		clear();
		puts("Song not found");

		return;
	}

	clear();

	printf("Enter rating from 1 - 5 (%d):\n", selected->data.rating);

	int rating;
	int num_read = -1;
	do {
		if (num_read != -1) puts("Invalid input");

		NEWLINE;
		printf("> ");

		num_read = scanf("%d", &rating);
		consume_input();
	} while (num_read != 1 || rating < 1 || rating > 5);

	selected->data.rating = rating;

	clear();

	puts("Successfully updated rating!");
}

// allows user to select a song and plays songs in order
void play(Node *head) {
	int count = print_list(head);

	NEWLINE;
	puts("Select a song to play:");

	int choice;
	int num_read = -1;
	do {
		if (num_read != -1) puts("Invalid input");

		NEWLINE;
		printf("> ");

		num_read = scanf("%d", &choice);
		consume_input();
	} while (num_read != 1 || choice < 1 || choice > count);
	--choice;

	for (int i = 0; i < choice; ++i)
		head = head->next;

	int i = 0;
	for (Node *curr = head; i < get_length(head); curr = curr->next, ++i) {
		clear();

		puts("Playing...");
		NEWLINE;
		printf("🎵 %s", curr->data.title);
		// https://stackoverflow.com/questions/1716296/why-does-printf-not-flush-after-the-call-unless-a-newline-is-in-the-format-strin
		fflush(stdout);

		_sleep(1);
	}

	clear();

	puts("End of playlist");
}

// prompts user for song details and inserts to front of list
void insert(Node **head) {
	Record data;
	read_str(data.artist, "Artist", 1);
	read_str(data.album, "Album", 1);
	read_str(data.title, "Title", 1);
	read_str(data.genre, "Genre", 1);
	read_int(&data.length.minutes, "Minutes", 1);
	read_int(&data.length.seconds, "Seconds", 1);
	read_int(&data.plays, "Plays", 1);
	read_int(&data.rating, "Rating", 1);

	clear();

	if (insert_front(head, data))
		printf("Successfully inserted %s!\n", data.title);
	else
		puts("Failed to insert new record");
}

void _delete(Node **head) {
	char title[MAX_STR];

	printf("Delete song by title: ");
	fgets(title, MAX_STR, stdin);
	title[strlen(title) - 1] = '\0';

	clear();

	if (delete_node(head, title))
		printf("Successfully deleted %s!\n", title);
	else
		puts("Song not found");
}

void sort(Node *head) {
	puts("Select a sorting method:");
	NEWLINE;
	puts("1. Sort based on artist (A-Z)");
	puts("2. Sort based on album  (A-Z)");
	puts("3. Sort based on rating (1-5)");
	puts("4. Sort based on plays  (largest-smallest)");

	int choice;
	int num_read = -1;
	do {
		if (num_read != -1) puts("Invalid input");

		NEWLINE;
		printf("> ");

		num_read = scanf("%d", &choice);
		consume_input();
	} while (num_read != 1 || choice < 1 || choice > 4);

	// choice is 1-4, same as enum
	sort_list(head, choice);

	clear();

	puts("Successfully sorted list!");
}

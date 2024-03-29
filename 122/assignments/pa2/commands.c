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

// writes str to stream, adds quotes if str contains a comma
void write_field(FILE *stream, char *str) {
	if (strchr(str, ','))
		fprintf(stream, "\"");
	fprintf(stream, "%s", str);
	if (strchr(str, ','))
		fprintf(stream, "\"");

	fprintf(stream, ",");
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
		Record record = head->data;
		// add quotes for commas
		write_field(stream, head->data.artist);
		write_field(stream, head->data.album);
		write_field(stream, head->data.title);
		write_field(stream, head->data.genre);

		fprintf(stream, "%d:%d,%d,%d\n", head->data.length.minutes,
			head->data.length.seconds, head->data.plays,
			head->data.rating);

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
	if (found != head)
		free_list(&found);
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
	Node *selected = find_one_by_title(head, curr->data.title);

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

// rate a song by title
void rate(Node *head) {
	char title[MAX_STR];

	printf("Rate song by title: ");
	fgets(title, MAX_STR, stdin);
	title[strlen(title) - 1] = '\0';

	Node *selected = find_one_by_title(head, title);
	if (selected == NULL) {
		puts("Song not found");
		return;
	}

	clear();

	printf("Enter rating from 1 - 5 (%d):\n", selected->data.rating);

	int rating;
	int num_read = -1;
	do {
		if (num_read != -1)
			puts("Invalid input");

		NEWLINE;
		printf("> ");

		num_read = scanf("%d", &rating);
		consume_input();
	} while (num_read != 1 || rating < 1 || rating > 5);

	selected->data.rating = rating;
}

// allows user to select a song and plays songs in order
void play(Node *head) {
	int count = print_list(head);

	NEWLINE;
	puts("Select a song to play:");

	int choice;
	int num_read = -1;
	do {
		if (num_read != -1)
			puts("Invalid input");

		NEWLINE;
		printf("> ");

		num_read = scanf("%d", &choice);
		consume_input();
	} while (num_read != 1 || choice < 1 || choice > count);
	--choice;

	for (int i = 0; i < choice; ++i)
		head = head->next;

	for (; head != NULL; head = head->next) {
		clear();

		puts("Playing...");
		NEWLINE;
		printf("🎵 %s", head->data.title);
		// https://stackoverflow.com/questions/1716296/why-does-printf-not-flush-after-the-call-unless-a-newline-is-in-the-format-strin
		fflush(stdout);

		_sleep(1);
	}

	clear();

	puts("End of playlist");
}

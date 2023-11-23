#include "io.h"

// Waits for Enter to be pressed
void wait_for_enter(void) {
	printf(GREEN "Press Enter to continue..." RESET);
	char c;
	scanf("%c", &c);
}

/*
 * Clears the console
 *
 * Pre-conditions: _WIN_32 is defined for Windows systems
 *
 * Post-conditions: Terminal is cleared
 */
void clear(void) {
	// https://stackoverflow.com/a/36253316
#ifdef _WIN_32
	system("cls");
#else
	system("clear");
#endif
}

/*
 * Consume input until \n
 *
 * Post-conditions: scanf() will be ready for the next read
 */
void consume_input(void) {
	// note: gcc on my system does not produce a warning for this line
	for (char c; c != '\n'; scanf("%c", &c))
		;
}

void warn(char *message) { printf(RED "🚨 Warning: %s\n" RESET, message); }

void write_hand(Hand *hand, int visible, int show_ids) {
	const char *suit[4] = {"♥️ ", "♦️ ", "♣️ ", "♠️ "};
	// kind of scuffed, but Ace is the highest card
	const char *face[13] = {"2", "3",  "4", "5", "6", "7", "8",
				"9", "10", "J", "Q", "K", "A"};

	if (show_ids)
		puts("   1️     2️     3️     4️     5️ ");
	printf(" ");
	for (int i = 0; i < 5; ++i)
		printf("╭────╮ ");
	NEWLINE;
	printf(" ");
	for (int i = 0; i < 5; ++i)
		printf("│%-4s│ ", visible ? face[hand->cards[i].face] : "?");
	NEWLINE;
	printf(" ");
	for (int i = 0; i < 5; ++i)
		printf("│ %s │ ", visible ? suit[hand->cards[i].suit] : "❔");
	NEWLINE;
	printf(" ");
	for (int i = 0; i < 5; ++i)
		printf("│%4s│ ", visible ? face[hand->cards[i].face] : "?");
	NEWLINE;
	printf(" ");
	for (int i = 0; i < 5; ++i)
		printf("╰────╯ ");
	NEWLINE;
}

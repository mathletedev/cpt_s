#include "io.h"

/* Waits for Enter to be pressed
 *
 * Pre-conditions: consume_input() has been called to avoid "skipping"
 */
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

/*
 * Writes a warning
 *
 * Parameters:
 * - char *message: Info for the warning
 */
void warn(char *message) { printf(RED "🚨 Warning: %s\n" RESET, message); }

/*
 * Writes a menu
 *
 * Returns a validated user choice (1, 2, or 3)
 */
int menu(void) {
	int valid = 1;
	char message[MESSAGE_SIZE];
	int choice;

	do {
		clear();
		NEWLINE;

		// https://patorjk.com/software/taag/#p=display&f=Graceful&t=Poker
		printf(RED);
		printf(
		    // clang-format off
		"   ____   __  __ _  ____  ____ \n"
		"  (  _ \\ /  \\(  / )(  __)(  _ \\\n"
		"   ) __/(  O ))  (  ) _)  )   /\n"
		"  (__)   \\__/(__\\_)(____)(__\\_)\n"
		    // clang-format on
		);
		printf(RESET);
		NEWLINE;

		puts(CYAN " 1. " MAGENTA "View rules");
		puts(CYAN " 2. " MAGENTA "Play game");
		puts(CYAN " 3. " MAGENTA "Exit" RESET);
		NEWLINE;

		if (!valid) {
			warn(message);
			NEWLINE;
		}

		printf(" > ");

		valid = 0;

		int data;
		int num_read = scanf("%d", &data);
		consume_input();

		if (num_read != 1) {
			strncpy(message, "Input must be a single integer",
				MESSAGE_SIZE);
			continue;
		}
		if (data < 1 || data > 3) {
			strncpy(message, "Input must be between 1 and 3",
				MESSAGE_SIZE);
			continue;
		}

		valid = 1;
		choice = data;
	} while (!valid);

	return choice;
}

// Writes the game rules
void rules(void) {
	clear();
	NEWLINE;

	printf(YELLOW);
	// written with the help of ChatGPT
	// clang-format off
	puts(" 1. The computer dealer will shuffle and deal five cards to you.");
	puts(" 2. You can exchange up to 3 cards for new ones.");
	puts(" 3. The goal is to make the best hand possible.");
	puts(" 4. The computer dealer will then reveal its own hand.");
	puts(" 5. The player with the best hand wins.");
	puts(" 6. In case of a tie, the game is a draw.");
	puts(" 7. Enjoy the game and good luck!");
	// clang-format on
	printf(RESET);
	NEWLINE;
}

/*
 * Writes a hand
 *
 * Pre-conditions:
 * - Suits are all between 0 and 3
 * - Faces are all between 0 and 12
 *
 * Parameters:
 * - Hand *hand: Pointer to a hand
 * - int visible: 1 if values should be shown
 * - int show_ids: 1 if cards should have IDs above them
 */
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
		printf("│ %s│ ", visible ? suit[hand->cards[i].suit] : "❔ ");
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

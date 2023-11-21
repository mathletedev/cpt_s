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

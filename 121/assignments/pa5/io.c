/*
 * Name: Neal Wang
 * Due Date: 2023-10-25
 * Lecture: 02
 * Lab: 25
 * Assignment: PA 5
 * Description: Input/ouput utilities
 */

#include "io.h"

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
 * Waits for any key
 */
void wait_for_keypress(void) {
	char key;
	scanf("%c", &key);
}

/*
 * Writes a question
 *
 * Parameters:
 * - char *question: Question to ask
 */
void write_question(char *question) {
	printf(MAGENTA "❔ %s\n" RESET, question);
}

/*
 * Writes a prompt
 *
 * Parameters:
 * - char *question: Question to ask
 */
void write_prompt(char *question) {
	if (question != NULL) {
		write_question(question);
		NEWLINE;
	}
	printf("   > ");
}

/*
 * Writes an option
 *
 * Parameters:
 * - char label: Label of the prompt (surrounded in parentheses)
 * - char *description: Description of the prompt
 */
void write_option(char label, char *description) {
	printf(CYAN "   (%c)" RESET " %s\n", label, description);
}

/*
 * Writes a combination option
 *
 * Parameters:
 * - char label: Label of the prompt (surrounded in parentheses)
 * - char *description: Description of the prompt
 * - int points: points awarded for the combination
 */
void write_combination(char label, char *description, int points) {
	printf(CYAN "   (%c)" RESET " %s" YELLOW "%d\n" RESET, label,
	       description, points);
}

/*
 * Reads and validates a character option
 *
 * Parameters:
 * - char *labels: Array of valid options
 * - char *input_ptr: Pointer to input variable
 *
 * Returns whether or not the input was valid
 */
int read_option(char *labels, char *input_ptr) {
	int valid = 1;

	// check if scanf found 1 character
	if (scanf(" %c", input_ptr) != 1)
		valid = 0;

	// consume scanf until newline
	for (char consumed; consumed != '\n'; scanf("%c", &consumed))
		;

	// check if input is contained in labels
	// https://www.tutorialspoint.com/c_standard_library/c_function_strchr.htm
	if (strchr(labels, *input_ptr) == NULL)
		valid = 0;

	return valid;
}

/*
 * Writes a warning for invalid input
 */
void warn_invalid(void) { printf(RED "🚨 Invalid input\n" RESET); }

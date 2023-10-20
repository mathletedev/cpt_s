#include "headers.h"

int main(void) {
	char name[20] = {'J', 'a', 'n', 'e', '\0'};
	char name2[10] = "Joe";

	// char *name3 = "Jill"; // immutable
	const char *name3 = "Jill";
	const char *const name4 = "James";

	printf("Hello %s!\n", name);
	printf("Hello %s!\n", name + 2);

	// writes a string with newline
	puts(name);

	name[0] = 'L';
	puts(name);

	// this will crash
	/* name3[0] = 'B'; */
	/* puts(name3); */

	name3 = "Bill";
	puts(name3);

	// can't modify const
	/* name4 = "Kevin"; */

	printf("Enter a name: ");
	// will crash if input is more than 19 characters
	// scans up to whitespace
	/* scanf("%s", name); */
	/* puts(name); */

	// safer way to read string
	// reads up to 19 characters (leaves room for null character)
	fgets(name, 20, stdin);

	// pointer assignment - does not work
	/* name2 = name; */

	// possible crash - name is longer than name2
	/* strcpy(name2, name); */
	/* puts(name2); */

	strncpy(name2, name, 9);
	puts(name2);

	return 0;
}

#include "utils.h"

// Waits for Enter to be pressed
void wait_for_enter(void) {
	printf(GREEN "Press Enter to continue..." RESET);
	char c;
	scanf("%c", &c);
}

void write_hand(Hand hand, int visible) {
	const char *suit[4] = {"♥️ ", "♦️ ", "♣️ ", "♠️ "};
	const char *face[13] = {"A", "2", "3",	"4", "5", "6", "7",
				"8", "9", "10", "J", "Q", "K"};

	for (int i = 0; i < 5; ++i)
		printf("╭────╮ ");
	printf("\n");
	for (int i = 0; i < 5; ++i)
		printf("│%-4s│ ", visible ? face[hand.cards[i].face] : "?");
	printf("\n");
	for (int i = 0; i < 5; ++i)
		printf("│ %s │ ", visible ? suit[hand.cards[i].suit] : "❔");
	printf("\n");
	for (int i = 0; i < 5; ++i)
		printf("│%4s│ ", visible ? face[hand.cards[i].face] : "?");
	printf("\n");
	for (int i = 0; i < 5; ++i)
		printf("╰────╯ ");
	printf("\n");
}

#include "utils.h"

void write_hand(Hand hand, int visible, int show_ids) {
	const char *suit[4] = {"♥️ ", "♦️ ", "♣️ ", "♠️ "};
	const char *face[13] = {"A", "2", "3",	"4", "5", "6", "7",
				"8", "9", "10", "J", "Q", "K"};

	if (show_ids)
		puts("   1️     2️     3️     4️     5️ ");
	printf(" ");
	for (int i = 0; i < 5; ++i)
		printf("╭────╮ ");
	NEWLINE;
	printf(" ");
	for (int i = 0; i < 5; ++i)
		printf("│%-4s│ ", visible ? face[hand.cards[i].face] : "?");
	NEWLINE;
	printf(" ");
	for (int i = 0; i < 5; ++i)
		printf("│ %s │ ", visible ? suit[hand.cards[i].suit] : "❔");
	NEWLINE;
	printf(" ");
	for (int i = 0; i < 5; ++i)
		printf("│%4s│ ", visible ? face[hand.cards[i].face] : "?");
	NEWLINE;
	printf(" ");
	for (int i = 0; i < 5; ++i)
		printf("╰────╯ ");
	NEWLINE;
}

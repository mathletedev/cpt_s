#include "hand.h"

void sort(int *frequency, int *res) {
	for (int i = 0; i < NUM_CARDS; ++i)
		res[i] = -1;

	for (int i = NUM_FACES - 1; i >= 0; --i) {
		if (!frequency[i])
			continue;

		for (int j = 0; j < NUM_CARDS; ++j) {
			if (res[j] == -1) {
				res[j] = i;
				break;
			}
		}
	}
}

int qual_x(int *frequency, int x, int *max) {
	for (int i = 0; i < NUM_FACES; ++i) {
		if (frequency[i] == x)
			// weight the x-of-a-kind but also include max card
			return i * NUM_FACES + (max[0] == i ? max[1] : max[0]);
	}
	return -1;
}

int qual_pair(int *frequency, int *max) { return qual_x(frequency, 2, max); }

int qual_two_pairs(int *frequency) {
	int first = -1, second = -1, rem = -1;
	// count backwards to automatically get max
	for (int i = NUM_FACES - 1; i >= 0; --i) {
		if (frequency[i] == 2) {
			if (first == -1)
				first = i;
			else
				second = i;
		} else if (frequency[i] == 1)
			rem = i;
	}

	if (first == -1 || second == -1 || rem == -1)
		return -1;
	// weight pairs higher
	return first * NUM_FACES * NUM_FACES + second * NUM_FACES + rem;
}

int qual_three(int *frequency, int *max) { return qual_x(frequency, 3, max); }

int qual_four(int *frequency, int *max) { return qual_x(frequency, 4, max); }

int qual_full(int *frequency) {
	int pair = -1, three = -1;

	for (int i = 0; i < NUM_FACES; ++i) {
		if (frequency[i] == 2)
			pair = i;
		else if (frequency[i] == 3)
			three = i;
	}

	if (pair == -1 || three == -1)
		return -1;
	return three * NUM_FACES + pair;
}

int qual_flush(int *frequency, Hand *hand, int *max) {
	for (int i = 1; i < NUM_CARDS; ++i) {
		if (hand->cards[i].suit != hand->cards[0].suit)
			return -1;
	}

	return max[0];
}

int qual_straight(int *frequency) {
	int length = 0;
	// since Ace can be used as a 1, bring Ace to the front
	if (frequency[NUM_FACES - 1] == 1)
		length = 1;

	for (int i = 0; i < NUM_FACES; ++i) {
		if (frequency[i]) {
			++length;

			if (length == 5)
				// ending index = max card
				return i;
			continue;
		}

		// reset length if there's a break
		// only useful for high/low card Ace
		if (length)
			length = 0;
	}

	return -1;
}

int qual(Hand *hand) {
	int frequency[NUM_FACES] = {0};
	for (int i = 0; i < NUM_CARDS; ++i)
		++frequency[hand->cards[i].face];

	int max[NUM_CARDS];
	sort(frequency, max);

	int res = qual_straight(frequency);
	if (res != -1 && qual_flush(frequency, hand, max) != -1)
		// weight higher quality hands
		return STRAIGHT_FLUSH * WEIGHT + res;

	res = qual_four(frequency, max);
	if (res != -1)
		return FOUR * WEIGHT + res;

	res = qual_full(frequency);
	if (res != -1)
		return FULL * WEIGHT + res;

	res = qual_flush(frequency, hand, max);
	if (res != -1)
		return FLUSH * WEIGHT + res;

	res = qual_straight(frequency);
	if (res != -1)
		return STRAIGHT * WEIGHT + res;

	res = qual_three(frequency, max);
	if (res != -1)
		return THREE * WEIGHT + res;

	// TODOOOOOOOOO
	res = qual_two_pairs(frequency);
	if (res != -1)
		return TWO_PAIRS * WEIGHT + res;

	res = qual_pair(frequency, max);
	if (res != -1)
		return PAIR * WEIGHT + res;

	// if no combinations, return highest card
	return SINGLE * WEIGHT + max[0];
}

int winner(Hand *dealer_hand, Hand *player_hand) {
	int dealer_qual = qual(dealer_hand);
	int player_qual = qual(player_hand);

	// 0: tie
	if (player_qual == dealer_qual)
		return 0;
	// 1: player won
	// -1: dealer won
	return (player_qual > dealer_qual) * 2 - 1;
}

int ai_x(Hand *hand, int *frequency, int x) {
	// which card is being used for the combination?
	int used;
	for (int i = 0; i < NUM_FACES; ++i) {
		if (frequency[i] == x)
			used = i;
	}

	// start by selecting no cards
	int mask = 0;
	for (int i = 0; i < NUM_CARDS; ++i) {
		// select card if not used and small
		if (hand->cards[i].face != used &&
		    // higher chance of picking a larger card
		    hand->cards[i].face < NUM_FACES / 2)
			mask |= 1 << i;
	}

	return mask;
}

int ai(Hand *hand) {
	int res = qual(hand);
	int strength = res / WEIGHT;

	int frequency[NUM_FACES] = {0};
	for (int i = 0; i < NUM_CARDS; ++i)
		++frequency[hand->cards[i].face];

	int max[NUM_CARDS];
	sort(frequency, max);

	// don't break straight flush
	if (strength >= STRAIGHT_FLUSH)
		return 0;

	if (strength >= FOUR)
		return ai_x(hand, frequency, 4);

	// don't break full house, flush, or straight
	if (strength >= STRAIGHT)
		return 0;

	if (strength >= THREE)
		return ai_x(hand, frequency, 3);

	if (strength >= TWO_PAIRS) {
		int first = -1, second = -1;
		for (int i = 0; i < NUM_FACES; ++i) {
			if (frequency[i] == 2) {
				if (first == -1)
					first = i;
				else
					second = i;
			}
		}

		int mask = 0;
		for (int i = 0; i < NUM_CARDS; ++i) {
			int face = hand->cards[i].face;
			// if remaining card is small, set bit
			if (face != first && face != second &&
			    face < NUM_FACES / 2)
				mask |= 1 << i;
		}

		return mask;
	}

	if (strength >= PAIR)
		return ai_x(hand, frequency, 2);

	// start by selecting everything
	int mask = ~0;
	for (int i = 0; i < NUM_CARDS; ++i) {
		// keep high card by reversing bit
		if (hand->cards[i].face == max[0])
			mask ^= 1 << i;
	}

	return mask;
}

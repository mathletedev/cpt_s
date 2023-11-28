#include "hand.h"

/*
 * Sorts frequency array in descending order
 *
 * Post-conditions: res will be filled by card faces in descending order
 *
 * Parameters:
 * - int *frequency: Card frequency array
 * - int *res: Returned sorted array
 */
void sort(int *frequency, int *res) {
	int index = 0;

	for (int i = NUM_FACES - 1; i >= 0; --i) {
		for (int j = 0; j < frequency[i]; ++j)
			res[index++] = i;
	}
}

/*
 * Calculates the quality of a x-of-a-kind hand
 *
 * Parameters:
 * - int *frequency: Card frequency array
 * - int x: x-of-a-kind
 * - int *max: Sorted array
 *
 * Returns the quality of the hand
 */
int qual_x(int *frequency, int x, int *max) {
	for (int i = 0; i < NUM_FACES; ++i) {
		if (frequency[i] == x)
			// weight the x-of-a-kind but also include max card
			return i * NUM_FACES + (max[0] == i ? max[1] : max[0]);
	}

	return -1;
}

// Calls qual_x with 2-of-a-kind
int qual_pair(int *frequency, int *max) { return qual_x(frequency, 2, max); }

/*
 * Calculates the quality of a 2-pairs hand
 *
 * Parameters:
 * - int *frequency: Card frequency array
 *
 * Returns the quality of the hand
 */
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

// Calls qual_x with 3-of-a-kind
int qual_three(int *frequency, int *max) { return qual_x(frequency, 3, max); }

// Calls qual_x with 4-of-a-kind
int qual_four(int *frequency, int *max) { return qual_x(frequency, 4, max); }

/*
 * Calculates the quality of a full house
 *
 * Parameters:
 * - int *frequency: Card frequency array
 *
 * Returns the quality of the hand
 */
int qual_full(int *frequency) {
	// find the pair and three
	int pair = -1, three = -1;

	for (int i = 0; i < NUM_FACES; ++i) {
		if (frequency[i] == 2)
			pair = i;
		else if (frequency[i] == 3)
			three = i;
	}

	// not a full house if either is -1
	if (pair == -1 || three == -1)
		return -1;
	return three * NUM_FACES + pair;
}

/*
 * Calculates the quality of a flush
 *
 * Parameters:
 * - int *frequency: Card frequency array
 * - Hand *hand: Pointer to player's hand
 * - int *max: Sorted array
 *
 * Returns the quality of the hand
 */
int qual_flush(int *frequency, Hand *hand, int *max) {
	for (int i = 1; i < NUM_CARDS; ++i) {
		// check all cards against first card for same suit
		if (hand->cards[i].suit != hand->cards[0].suit)
			return -1;
	}

	return max[0];
}

/*
 * Calculates the quality of a straight
 *
 * Parameters:
 * - int *frequency: Card frequency array
 *
 * Returns the quality of the hand
 */
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

/*
 * Calculates the quality of a hand (aggregate of all qual functions)
 *
 * Parameters:
 * - Hand *hand: Pointer to player's hand
 *
 * Returns the quality of the hand
 */
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

	res = qual_two_pairs(frequency);
	if (res != -1)
		return TWO_PAIRS * WEIGHT + res;

	res = qual_pair(frequency, max);
	if (res != -1)
		return PAIR * WEIGHT + res;

	// if no combinations, return highest card
	return SINGLE * WEIGHT + max[0];
}

/*
 * Finds which player won
 *
 * Parameters:
 * - Hand *dealer_hand: Pointer to dealer's hand
 * - Hand *player_hand: Pointer to (human) player's hand
 *
 * Returns:
 * - 1 if player won
 * - 0 if tie
 * - -1 if dealer won
 */
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

/*
 * Selects cards to re-draw for an x-of-a-kind hand
 *
 * Parameters:
 * - Hand *hand: Pointer to player's hand
 * - int *frequency: Card frequency array
 * - int x: x-of-a-kind
 *
 * Returns a bitmask for selected cards
 */
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

/*
 * Selects cards to re-draw
 * Keeps cards needed for combination
 * Re-draws low cards
 *
 * Parameters:
 * - Hand *hand: Pointer to player's hand
 *
 * Returns a bitmask for selected cards
 */
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

	// use ai_x for any x-of-a-kind hands
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
		int face = hand->cards[i].face;
		// keep two highest cards
		if (face == max[0] || face == max[1])
			// reverse bit
			mask ^= 1 << i;
	}

	return mask;
}

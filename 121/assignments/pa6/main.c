#include "headers.h"

int main(void) {
	srand(time(NULL));
	FILE *logfile = fopen("battleship.log", "w");

	if (logfile == NULL) {
		puts(RED "❌ Unable to open logfile for writing");
		return 1;
	}

	int curr_player = rand() % 2;

	Stats p1_stats = {0, 0, 0, 0};
	Stats p2_stats = {0, 0, 0, 0};

	Board p1_board;
	p1_board.rows = ROWS;
	p1_board.cols = COLS;
	init_board(&p1_board);
	Board p2_board;
	p2_board.rows = ROWS;
	p2_board.cols = COLS;
	init_board(&p2_board);

	int p1_frequency[5] = {0};
	int p2_frequency[5] = {0};

	clear();

	welcome();
	wait_for_keypress();

	clear();

	puts(MAGENTA "📝 How would you like to place your ships?" RESET);
	NEWLINE;
	puts(CYAN "(0)" RESET " Manual");
	puts(CYAN "(1)" RESET " Random");
	NEWLINE;

	int selection;
	while (1) {
		printf(MAGENTA "Select an option (0 or 1): " RESET);
		if (scanf("%d", &selection) == 1 && selection >= 0 &&
		    selection <= 1)
			break;
		else {
			consume_input();
			warn_invalid();
		}
	}
	consume_input();

	NEWLINE;

	if (selection == 1)
		place_random_all(&p1_board);
	else
		place_manual_all(&p1_board);

	place_random_all(&p2_board);

	puts(GREEN "✅ Boards generated successfully\n");

	wait_for_keypress();

	while (1) {
		clear();

		puts(YELLOW "🚢 Player 1's board");
		NEWLINE;
		write_board(p1_board, 1);
		NEWLINE;
		puts(YELLOW "🔎 Player 2's board");
		NEWLINE;
		write_board(p2_board, 0);
		NEWLINE;

		Coordinates target;

		if (curr_player == HUMAN) {
			while (1) {
				printf(MAGENTA "🎯 Enter a target: " RESET);
				if (read_coordinates(&target, p2_board))
					break;
				else {
					consume_input();
					warn_invalid();
				}
			}
			consume_input();
		} else {
			target = random_target(p1_board);
			printf(MAGENTA "🎯 Player 2 selects: " RESET "...");
			fflush(stdout);
			sleep(1);

			// "\r" moves carriage to start of line
			// https://www.reddit.com/r/cpp_questions/comments/14ypjb6/how_do_i_replace_already_printed_text_in_the
			printf(MAGENTA "\r🎯 Player 2 selects: " RESET "%d %d\n",
			       target.row, target.col);
		}

		Board *enemy_board =
		    curr_player == HUMAN ? &p2_board : &p1_board;
		int *enemy_frequency =
		    curr_player == HUMAN ? p2_frequency : p1_frequency;
		Stats *curr_stats =
		    curr_player == HUMAN ? &p1_stats : &p2_stats;

		NEWLINE;

		char ship;
		int hit;
		take_shot(target, enemy_board, curr_stats, &ship, &hit);
		write_shot(target, hit);

		update_frequency(enemy_frequency, *enemy_board);

		int sunk = check_sunk(ship, enemy_frequency);
		if (sunk)
			write_sunk(ship);

		write_move(logfile, curr_player, target, ship != WATER,
			   sunk ? ship : ' ');

		curr_player = !curr_player;

		wait_for_keypress();

		if (check_lost(enemy_frequency))
			break;
	}

	clear();

	puts(RED "🏁 Game over!");
	NEWLINE;
	puts(YELLOW "🚢 Player 1's board");
	NEWLINE;
	write_board(p1_board, 1);
	NEWLINE;
	puts(YELLOW "🔎 Player 2's board");
	NEWLINE;
	write_board(p2_board, 1);
	NEWLINE;

	int winner = !curr_player + 1;

	printf(YELLOW "🏆 Player %d" GREEN " wins!\n" RESET, winner);
	NEWLINE;

	fprintf(logfile, "\n");
	fprintf(logfile, "Player 1 %s, Player 2 %s\n",
		winner == 1 ? "wins" : "loses", winner == 2 ? "wins" : "loses");
	fprintf(logfile, "\n");
	write_stats(logfile, 1, p1_stats);
	fprintf(logfile, "\n");
	write_stats(logfile, 2, p2_stats);

	puts(GREEN "✅ Statistics outputted to logfile successfully!");

	fclose(logfile);

	return 0;
}

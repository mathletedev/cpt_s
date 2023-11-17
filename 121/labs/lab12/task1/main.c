#include "headers.h"

int main(void) {
	char maze[ROWS][COLS] = {
	    {' ', 'X', ' ', ' ', ' ', ' ', ' ', ' '},
	    {' ', 'X', ' ', 'X', 'X', 'X', 'X', ' '},
	    {' ', 'X', ' ', 'X', ' ', ' ', ' ', ' '},
	    {' ', 'X', ' ', 'X', ' ', 'X', 'X', 'X'},
	    {' ', 'X', ' ', 'X', ' ', ' ', ' ', ' '},
	    {' ', 'X', ' ', 'X', 'X', ' ', ' ', ' '},
	    {' ', 'X', ' ', 'X', ' ', ' ', 'X', ' '},
	    {' ', ' ', ' ', 'X', ' ', ' ', ' ', ' '},
	};

	int visited[ROWS][COLS];
	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLS; ++j)
			visited[i][j] = 0;
	}

	Coord first = {0, 0};
	Coord path[1000];
	int depth = 0;
	dfs(first, path, maze, visited, &depth);

	for (int i = 0; i < depth; ++i)
		printf("%d: %d, %d\n", i + 1, path[i].x, path[i].y);

	printf("Solved in %d moves\n", depth);

	return 0;
}

#include "headers.h"

int dfs(Coord node, Coord *path, char maze[ROWS][COLS], int visited[ROWS][COLS],
	int *depth) {
	if (node.x < 0 || node.x >= ROWS || node.y < 0 || node.y >= COLS ||
	    maze[node.x][node.y] == 'X' || visited[node.x][node.y])
		return 0;

	if (node.x == ROWS - 1 && node.y == COLS - 1)
		return 1;

	visited[node.x][node.y] = 1;

	Coord dirs[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

	for (int i = 0; i < 4; ++i) {
		Coord next = node;
		next.x += dirs[i].x;
		next.y += dirs[i].y;

		if (dfs(next, path + 1, maze, visited, depth)) {
			path->x = next.x;
			path->y = next.y;

			++*depth;

			return 1;
		}
	}

	return 0;
}

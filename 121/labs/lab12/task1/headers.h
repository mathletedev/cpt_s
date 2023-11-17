#ifndef HEADERS_H
#define HEADERS_H

#include <stdio.h>

#define ROWS 8
#define COLS 8

typedef struct coord {
	int x;
	int y;
} Coord;

int dfs(Coord node, Coord *path, char maze[ROWS][COLS], int visited[ROWS][COLS],
	int *depth);

#endif

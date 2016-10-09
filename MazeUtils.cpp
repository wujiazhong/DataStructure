#include "MazeUtils.h"
#include <stdio.h>

int Pass(int maze[8][8], PosType pos) {
	if (maze[pos.x][pos.y] != 0 && maze[pos.x][pos.y] != -1) return 1;
	else return 0;
}

void FootPrint(PosType pos) {
	printf("(%d, %d)", pos.x, pos.y);
}
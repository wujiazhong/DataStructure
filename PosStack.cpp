#include "PosStack.h"
#include <stdlib.h>
#include <stdio.h>

Status InitPosStack(PosStack &S) {
	S.base = (MazeStackType *)malloc(POS_STATCK_INIT_SIZE * sizeof(MazeStackType));
	if (!S.base) exit(OVERFLOW);
	S.top = S.base;
	S.statcksize = POS_STATCK_INIT_SIZE;
	return OK;
}

Status GetPosTop(PosStack S, MazeStackType &e) {
	if (S.top == S.base) return ERROR;
	e = *(S.top - 1);
	return OK;
}

Status PushPos(PosStack &S, MazeStackType e) {
	if (S.top - S.base >= S.statcksize) {
		S.base = (MazeStackType *)realloc(S.base, (S.statcksize + POS_STATCKINCREMENT) * sizeof(MazeStackType));

		if (!S.base) exit(OVERFLOW);
		S.top = S.base + S.statcksize;
		S.statcksize += POS_STATCKINCREMENT;
	}

	CopyMazeStackType(S.top, e);
	++S.top;
	return OK;
}

Status PopPos(PosStack &S, MazeStackType &e) {
	if (S.top == S.base) return ERROR;
	CopyMazeStackType(&e, *(--S.top));
	return OK;
}

Status PosStackEmpty(PosStack S) {
	if (S.base == S.top) return TRUE;
	else return FALSE;
}

Status DestroyPosStack(PosStack &S) {
	free(S.base);
	S.base = NULL;
	S.top = NULL;
	S.statcksize = 0;
	return OK;
}

Status ClearPosStack(PosStack &S) {
	S.top = S.base;
	return OK;
}

Status PrintPosStack(PosStack S) {
	MazeStackType *ptr;
	ptr = S.base;
	while (ptr != S.top) {
		//printf("(%d, %d)", ptr->ord, ptr->y);
		++ptr;
	}
	putchar('\n');
	return OK;
}

Status CopyMazeStackType(MazeStackType *ptr, MazeStackType e) {
	ptr->ord = e.ord;
	ptr->di = e.di;
	ptr->seat.x = e.seat.x;
	ptr->seat.y = e.seat.y;
	return OK;
}

PosType nextPos(PosType pos, int di) {
	switch (di){
	case 1:pos.y += 1; break;
	case 2:pos.x -= 1; break;
	case 3:pos.y -= 1; break;
	case 4:pos.x += 1; break;
	default:break;
	}
	return pos;
}
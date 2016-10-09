#pragma once
#ifndef POSTYPE_H
#define POSTYPE_H

#include "Status.h"

typedef struct {
	int x;
	int y;
}PosType;

typedef struct {
	int ord;
	PosType seat;
	int di;
} MazeStackType;

#define POS_STATCK_INIT_SIZE 100
#define POS_STATCKINCREMENT 10

typedef struct {
	MazeStackType *base;
	MazeStackType *top;
	int statcksize;
} PosStack;

PosType nextPos(PosType curPos, int di);
Status CopyMazeStackType(MazeStackType *ptr, MazeStackType e);
Status InitPosStack(PosStack &S);
Status GetPosTop(PosStack S, MazeStackType &e);
Status PushPos(PosStack &S, MazeStackType e);
Status PopPos(PosStack &S, MazeStackType &e);
Status PosStackEmpty(PosStack S);
Status DestroyPosStack(PosStack &S);
Status ClearPosStack(PosStack &S);
Status PrintPosStack(PosStack S);

#endif // !POSTYPE_H
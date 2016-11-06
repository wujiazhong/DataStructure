#include "SqStack.h"
#include "MazeUtils.h"
#include <iostream>
#include <string>
#include <stdio.h>

//数制转换
void conversion() {
	SqStack S;
	int N;
	InitStack(S);
	scanf("%d", &N);

	while (N) {
		SElemType e;
		e = N % 8;
		Push(S, e);
		N /= 8;
	}

	while (!StackEmpty(S)) {
		SElemType e;
		Pop(S, e);
		printf("%d", e);
	}
	DestroyStack(S);
}

//行编辑程序
void lineEdit() {
	SqStack S;
	InitStack(S);
	char ch;
	ch = getchar();
	while (ch != EOF) {
		while (ch != EOF && ch != '\n') {
			switch (ch) {
			case '#': Pop(S, ch); break;
			case '@': ClearStack(S); break;
			default: Push(S, createSElemType(ch)); break;
			}
			ch = getchar();
		}
		PrintStack(S);
		ClearStack(S);
		if (ch != EOF) ch = getchar();
	}
	DestroyStack(S);
}

Status MazePath() {
	int MAZE[8][8] = { { 0,0,0,0,0,0,0,0 },{ 0,0,1,0,0,1,0,0 },{ 0,1,1,0,0,0,1,0 },{ 0,1,0,0,0,0,0,0 },
						   { 0,1,1,1,0,0,1,0 },{ 0,0,0,1,0,0,1,0 },{ 0,0,0,1,1,1,1,0 },{ 0,0,0,0,0,0,0,0 } };
	PosType start; 
	start.x = 1;
	start.y = 2;

	PosType end;
	end.x = 4;
	end.y = 6;

	PosStack S;
	InitPosStack(S);
	PosType curPos;
	curPos.x = start.x;
	curPos.y = start.y;
	int curstep = 1;
	MazeStackType e;

	do {
		if (Pass(MAZE, curPos)) {
			MAZE[curPos.x][curPos.y] = 0;
			FootPrint(curPos);
			e.ord = curstep;
			e.di = 1;
			e.seat = curPos;
			PushPos(S, e);

			if (curPos.x == end.x && curPos.y == end.y) return TRUE;
			curPos = nextPos(curPos, e.di);
			++curstep;
		}
		else {
			PopPos(S, e);
			while (e.di == 4 && !PosStackEmpty(S)) {
				MAZE[e.seat.x][e.seat.y] = -1;
				PopPos(S, e);
			}
			if (e.di < 4) {
				e.di++;
				PushPos(S, e);
				curPos = nextPos(e.seat, e.di);
			}
		}
	} while (!PosStackEmpty(S));
//	PrintPosStack(S);
	return OK;
}

template <typename T1, typename T2>
void doSth(T1 a, T2 b) {
	std::cout << a << b;
}
/*
int main(int argc, char* argv) {
//	conversion();
//	lineEdit();
//	MazePath();
}
*/
#pragma once
#ifndef BISTACK_H
#define BISTACK_H

#ifndef STATCK_INIT_SIZE
	#define STATCK_INIT_SIZE 100
#endif 
#ifndef STATCKINCREMENT
	#define STATCKINCREMENT 10
#endif
#include "BiTNode.h"
#include "Status.h"

typedef struct {
	BiTNode **base;
	BiTNode **top;
	int statcksize;
} BiTStack;

Status InitStack(BiTStack &S);
Status GetTop(BiTStack S, BiTNode*** e);
Status Push(BiTStack &S, BiTNode *e);
Status Pop(BiTStack &S, BiTNode** e);
Status StackEmpty(BiTStack S);
Status DestroyStack(BiTStack &S);
Status ClearStack(BiTStack &S);
Status PrintStack(BiTStack S);

#endif // !BISTACK_H

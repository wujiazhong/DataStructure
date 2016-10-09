#pragma once
#ifndef SQSTACK_H
#define SQSTACK_H

#define STATCK_INIT_SIZE 100
#define STATCKINCREMENT 10

#include "SElemType.h"
#include "Status.h"

typedef struct {
	SElemType *base;
	SElemType *top;
	int statcksize;
} SqStack;

Status InitStack(SqStack &S);
Status GetTop(SqStack S, SElemType &e);
Status Push(SqStack &S, SElemType e);
Status Pop(SqStack &S, SElemType &e);
Status StackEmpty(SqStack S);
Status DestroyStack(SqStack &S);
Status ClearStack(SqStack &S);
Status PrintStack(SqStack S);

#endif //  !SQSTACK_H
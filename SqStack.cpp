#include "SqStack.h"
#include <stdlib.h>
#include <stdio.h>

Status InitStack (SqStack &S) {
	S.base = (SElemType *)malloc(STATCK_INIT_SIZE * sizeof(SElemType));
	if (!S.base) exit(OVERFLOW);
	S.top = S.base;
	S.statcksize = STATCK_INIT_SIZE;
	return OK;
}

Status GetTop(SqStack S, SElemType &e) {
	if (S.top == S.base) return ERROR;
	e = *(S.top - 1);
	return OK;
}

Status Push(SqStack &S, SElemType e) {
	if (S.top - S.base >= S.statcksize) {
		S.base = (SElemType *)realloc(S.base, (S.statcksize + STATCKINCREMENT) * sizeof(SElemType));

		if (!S.base) exit(OVERFLOW);
		S.top = S.base + S.statcksize;
		S.statcksize += STATCKINCREMENT;
	}

	S.top->val = e.val;
	++S.top;
	return OK;
}

Status Pop(SqStack &S, SElemType &e) {
	if (S.top == S.base) return ERROR;
	e.val = (--S.top)->val;
	return OK;
}

Status StackEmpty(SqStack S) {
	if (S.base == S.top) return TRUE;
	else return FALSE;
}

Status DestroyStack(SqStack &S) {
	free(S.base);
	S.base = NULL;
	S.top = NULL;
	S.statcksize = 0;
	return OK;
}

Status ClearStack(SqStack &S) {
	S.top = S.base;
	return OK;
}

Status PrintStack(SqStack S) {
	SElemType *ptr;
	ptr = S.base;
	while (ptr != S.top) {
		putchar(ptr->val);
		++ptr;
	}
	putchar('\n');
	return OK;
}
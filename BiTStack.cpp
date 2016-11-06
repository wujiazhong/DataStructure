#include "BiTStack.h"
#include <stdlib.h>
#include <stdio.h>

Status InitStack(BiTStack &S) {
	S.base = (BiTNode **)malloc(STATCK_INIT_SIZE * sizeof(BiTNode*));
	if (!S.base) exit(OVERFLOW);
	S.top = S.base;
	S.statcksize = STATCK_INIT_SIZE;
	return OK;
}

Status GetTop(BiTStack S, BiTNode ***e) {
	if (S.top == S.base) return ERROR;
	BiTNode** ptr = S.top;
	*e = --ptr;
	return OK;
}

Status Push(BiTStack &S, BiTNode *e) {
	if (S.top - S.base >= S.statcksize) {
		S.base = (BiTNode **)realloc(S.base, (S.statcksize + STATCKINCREMENT) * sizeof(BiTNode*));

		if (!S.base) exit(OVERFLOW);
		S.top = S.base + S.statcksize;
		S.statcksize += STATCKINCREMENT;
	}

	*(S.top) = e;
	++S.top;
	return OK;
}

Status Pop(BiTStack &S, BiTNode **e) {
	if (S.top == S.base) return ERROR;
	*e = *(--S.top);
	return OK;
}

Status StackEmpty(BiTStack S) {
	if (S.base == S.top) return TRUE;
	else return FALSE;
}

Status DestroyStack(BiTStack &S) {
	free(S.base);
	S.base = NULL;
	S.top = NULL;
	S.statcksize = 0;
	return OK;
}

Status ClearStack(BiTStack &S) {
	S.top = S.base;
	return OK;
}

Status PrintStack(BiTStack S) {
	BiTNode *ptr;
	ptr = *S.base;
	while (ptr != *S.top) {
		putchar(ptr->data);
		++ptr;
	}
	putchar('\n');
	return OK;
}
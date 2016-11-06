/*#include "LinkList.h"
#include<iostream>

int main(int argc, char *argv) {
	LinkList L;
	InitList_L(L);

	void(*pf)(ElemType*);
	pf = visit;

	ElemType e1;
	e1 = 1;
	ListInsert_L(L, 1, e1);

	ElemType e2;
	e2 = 2;
	ListInsert_L(L, 2, e2);

	ElemType e3;
	ListDelete_L(L, 1, e3);
	ListTraverse_L(L, pf);

	int i;
	ListLength_L(L, i);
	printf("LinkList length is %d\n",i);

	ListInsert_L(L, 1, e1);
	ClearList_L(L);
	printf("LinkList head data %d\n", L->data);
	printf("LinkList is clear? %d\n", L->next == NULL);

	DestroyList_L(L);
	printf("LinkList is destroyed? %d\n", L == NULL);

	return 0;
}
*/
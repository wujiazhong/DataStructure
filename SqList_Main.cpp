#include "SqList.h"
#include<iostream>

/**
int main(int argc, char *argv) {
	SqList sqlist;
	ElemType e1;
	e1.val = 1;

	InitList_Sq(sqlist);
	ListInsert_Sq(sqlist, 1, e1);

	ElemType e2;
	e2.val = 2;
	ListInsert_Sq(sqlist, 2, e2);

	ElemType e3;
	GetElem_Sq(sqlist, 1, e3);
	//std::cout << e3.val;
	
	ElemType e4;
	PriorElem_Sq(sqlist, e2, e4);
	//std::cout << e4.val;

	ElemType e5;
	NextElem_Sq(sqlist, e1, e5);
	//std::cout << e5.val;

	ElemType e6;
	ListDelete_Sq(sqlist, 1, e6);
	//std::cout << e6.val;

	SqList L1;
	InitList_Sq(L1);
	ListInsert_Sq(L1, 1, e1);
	ListInsert_Sq(L1, 2, e2);
	
	SqList L2;
	InitList_Sq(L2);
	ListInsert_Sq(L2, 1, e1);
	ListInsert_Sq(L2, 2, e2);

	SqList L;
	//InitList_Sq(L);
	MergeList_Sq(L1, L2, L);

	void(*pf)(ElemType*);
	pf = visit;
	ListTraverse(L, pf);
	
	return 0;
}
**/
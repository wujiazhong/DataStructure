#pragma once
#ifndef LINKLIST_H
#define LINKLIST_H

#include "ElemType.h"
#include "Constant.h"

//此行的LNode是结构体struct LNode的一个别名
//*LinkList也是结构体struct LNode的一个别名
//换言之LinkList是结构体struct LNode类型的指针的别名
//也就是说  struct LNode *p;这条语句等同于LinkList p;
typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

int InitList_L(LinkList &L);
int GetElem_L(LinkList &L, int i, ElemType &e);
int ListDelete_L(LinkList &L, int i, ElemType &e);
int ListInsert_L(LinkList &L, int i, ElemType e);
void ListTraverse_L(LinkList L, void(*visit)(ElemType*));
int ListLength_L(LinkList L, int &i);
int DestroyList_L(LinkList &L);
int ClearList_L(LinkList &L);

#endif //!LINKLIST_H 
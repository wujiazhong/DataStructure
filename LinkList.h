#pragma once
#ifndef LINKLIST_H
#define LINKLIST_H

#include "ElemType.h"
#include "Status.h"

//此行的LNode是结构体struct LNode的一个别名
//*LinkList也是结构体struct LNode的一个别名
//换言之LinkList是结构体struct LNode类型的指针的别名
//也就是说  struct LNode *p;这条语句等同于LinkList p;
typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

Status InitList_L(LinkList &L);
Status GetElem_L(LinkList &L, int i, ElemType &e);
Status ListDelete_L(LinkList &L, int i, ElemType &e);
Status ListInsert_L(LinkList &L, int i, ElemType e);
void ListTraverse_L(LinkList L, void(*visit)(ElemType));
Status ListLength_L(LinkList L, int &i);
Status DestroyList_L(LinkList &L);
Status ClearList_L(LinkList &L);

#endif //!LINKLIST_H 
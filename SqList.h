#pragma once
#ifndef SQLIST_H
#define SQLIST_H

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

#include "ElemType.h"
#include "Status.h"

typedef struct {
	ElemType *elem;
	int length;
	int listsize;
} SqList;

Status InitList_Sq(SqList &L);
Status DestroyList_Sq(SqList &L);
Status ClearList_Sq(SqList &L);
Status GetElem_Sq(SqList &L, int i, ElemType &e);
int LocateElem_Sq(SqList L, ElemType e, int(*compare)(ElemType, ElemType));
bool ListEmpty_Sq(SqList &L);
int ListLength_Sq(SqList &L);
Status ListInsert_Sq(SqList &L, int i, ElemType e);
Status PriorElem_Sq(SqList L, ElemType cur_e, ElemType &pre_e);
Status NextElem_Sq(SqList L, ElemType cur_e, ElemType &post_e);
Status ListTraverse(SqList L, void(*visit)(ElemType*));
Status ListDelete_Sq(SqList L, int i, ElemType &e);
void MergeList_Sq(SqList L1, SqList L2, SqList &L);

#endif // !SQLIST_H
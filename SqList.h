#pragma once
#ifndef SQLIST_H
#define SQLIST_H

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

#include "Constant.h"
#include "ElemType.h"

typedef struct {
	ElemType *elem;
	int length;
	int listsize;
} SqList;

int InitList_Sq(SqList &L);
int DestroyList_Sq(SqList &L);
int ClearList_Sq(SqList &L);
int GetElem_Sq(SqList &L, int i, ElemType &e);
int LocateElem_Sq(SqList L, ElemType e, int(*compare)(ElemType, ElemType));
int ListEmpty_Sq(SqList &L);
int ListLength_Sq(SqList &L);
int ListInsert_Sq(SqList &L, int i, ElemType e);
int PriorElem_Sq(SqList L, ElemType cur_e, ElemType &pre_e);
int NextElem_Sq(SqList L, ElemType cur_e, ElemType &post_e);
int ListTraverse(SqList L, void(*visit)(ElemType*));
int ListDelete_Sq(SqList L, int i, ElemType &e);
void MergeList_Sq(SqList L1, SqList L2, SqList &L);

#endif // !SQLIST_H
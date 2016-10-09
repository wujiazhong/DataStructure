#include "LinkList.h"

int InitList_L(LinkList &L) {
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	L->data.val = 0;
	return OK;
}

int GetElem_L(LinkList &L, int i, ElemType &e) {
	LNode *p;
	p = L;	
	while (i--) p = p->next;
	e.val = p->data.val;

	return OK;
}

int ListDelete_L(LinkList &L, int i, ElemType &e) {
	LNode *p, *tmp;
	int j = 1;
	p = L;

	while (p && j < i) {
		p = p->next; ++j;
	}
	if (!p->next || j > i) return ERROR;
	tmp = p->next;
	p->next = tmp->next;
	e.val = tmp->data.val;
	free(tmp);
	tmp = NULL;
	return OK;
}

int ListInsert_L(LinkList &L, int i, ElemType e) {
	LNode *p, *node;
	int j = 0;
	p = L;
	
	while (p && j < i - 1) {
		p = p->next; ++j;
	}

	if (!p || j > i - 1) return ERROR;

	node = (LNode*)malloc(sizeof(LNode));
	node->data.val = e.val;
	node->next = p->next;
	p->next = node;
	return OK;
}

void ListTraverse_L(LinkList L, void(*visit)(ElemType*)) {
	LNode *p;
	p = L;

	while (p->next) {
		printf("%d\n", p->next->data.val);
		p = p->next;
	}
}

int DestroyList_L(LinkList &L) {
	LNode *p;

	while (L) {
		p = L->next;
		free(L);
		L = p;
	}
	return OK;
}

int ClearList_L(LinkList &L) {
	LNode *tmp;

	if (!L) return ERROR;
	while (L->next) {
		tmp = L->next;
		L->next = tmp->next;
		free(tmp);
		tmp = NULL;
	}
	return OK;
}

int ListLength_L(LinkList L, int &i) {
	i = 0;
	LNode *p;
	p = L;

	if (!p) return ERROR;
	while (p->next) {
		p = p->next;
		++i;
	}
	return OK;
}
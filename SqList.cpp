#include "SqList.h"
#include<iostream>

Status InitList_Sq(SqList &L) {
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L.elem) exit(OVERFLOW);
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return OK;
}

Status DestroyList_Sq(SqList &L) {
    if (L.elem) free(L.elem);
    L.elem = NULL;
    L.length = 0;
    L.listsize = 0;
    return OK;
}

Status ClearList_Sq(SqList &L)
{
    L.length = 0;
    return OK;
}

bool ListEmpty_Sq(SqList &L) {
    if (L.length)
            return true;
    else
            return false;
}

int ListLength_Sq(SqList &L) {
    return L.length;
}

Status GetElem_Sq(SqList &L, int i, ElemType &e) {
    if (i<1 || i>L.length) exit(ERROR);
    e = *(L.elem + i - 1);
    return OK;
}

int LocateElem_Sq(SqList L, ElemType e, int(*compare)(ElemType, ElemType)) {
    ElemType *q = L.elem;
    int i = 1;
    while (i <= L.length && !compare(*++q, e)) ++i;

    if (i <= L.length) return i;
    else return 0;
}

Status ListInsert_Sq(SqList &L, int i, ElemType e) {
    ElemType *newbase, *q, *p;
    if (i<1 || i>L.length + 1) 
            return ERROR;
    if (L.length >= L.listsize)
    {
            newbase = (ElemType *)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
            if (!newbase)
                    exit(OVERFLOW);
            L.elem = newbase;
            L.listsize += LISTINCREMENT;
    }
    q = L.elem + i - 1;
    for (p = L.elem + L.length - 1; p >= q; --p)
            *(++p) = *p;
    *q = e;
    ++L.length;
    return OK;
}

Status PriorElem_Sq(SqList L, ElemType cur_e, ElemType &pre_e) {
    int i = 2;
    ElemType *p = L.elem + 1;
    while (i <= L.length && !compare(*p, cur_e)) {
            i++;
            p++;
    }

    if (i > L.length) {
            return INFEASIBLE;
    }
    else {
            pre_e = *--p;
    }

    return OK;
}

Status NextElem_Sq(SqList L, ElemType cur_e, ElemType &post_e) {
    int i = 1;
    ElemType *p = L.elem;
    while (i < L.length && !compare(*p, cur_e)) {
            i++;
            p++;
    }

    if (i == L.length) {
            return INFEASIBLE;
    } 
    else {
            post_e = *++p;
    }
    return OK;
}

Status ListTraverse(SqList L, void(*visit)(ElemType*)) {
    ElemType *p;
    int i;
    p = L.elem;
    for (i = 1; i <= L.length; i++)
            visit(p++);
    printf("\n");
    return OK;
}

Status ListDelete_Sq(SqList L, int i, ElemType &e) {
    ElemType *q = L.elem + i -1;
    e = *q;

    for (int k = i; k < L.length; k++) {
            *q = *++q;
    }
    return OK;
}

void MergeList_Sq(SqList L1, SqList L2, SqList &L) {
    ElemType *p1, *p2, *p;
    p1 = L1.elem;
    p2 = L2.elem;

    L.listsize = L.length = L1.length + L2.length;
    L.elem = (ElemType *)malloc(L.listsize * sizeof(ElemType));
    p = L.elem;

    if (!L.elem) exit(OVERFLOW);

    ElemType *p1_last = L1.elem + L1.length - 1;
    ElemType *p2_last = L2.elem + L2.length - 1;
    while (p1 <= p1_last && p2 <= p2_last) {
            if (*p2 > *p1) {
                    *p = *p1;
                    ++p;
                    ++p1;
            }
            else 
            {
                    *p = *p2;
                    ++p;
                    ++p2;
            }
    }

    while (p1 <= p1_last) {
            *p = *p1;
            ++p;
            ++p1;
    }
    while (p2 <= p2_last) {
            *p = *p2;
            ++p;
            ++p2;
    }
}

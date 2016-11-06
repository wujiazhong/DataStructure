#pragma once
#ifndef BITREE_H
#define BITREE_H

#include "Status.h"
#include "BiTNode.h"

typedef BiTNode *BiTree;

Status InitBiTree(BiTree &T);
void CreateBiTree(BiTree &T);
Status PreOrderTraverse(BiTree &T, void(*visit)(SElemType));
Status PreOrderTraverse_recur(BiTree &T, void(*visit)(SElemType));
Status InOrderTraverse_recur(BiTree &T, void(*visit)(SElemType));
Status InOrderTraverse(BiTree &T, void(*visit)(SElemType));
Status PostOrderTraverse(BiTree &T, void(*visit)(SElemType));
Status PostOrderTraverse_recur(BiTree &T, void(*visit)(SElemType));

#endif //!BITREE_H
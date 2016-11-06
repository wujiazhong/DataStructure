#pragma once
#ifndef BITNODE_H
#define BITNODE_H
#include "SElemType.h"

typedef struct BiTNode {
	SElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode;

#endif // !BITNODE_H
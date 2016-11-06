#include "BiTree.h"
#include <iostream>
#include "BiTStack.h"

Status InitBiTree(BiTree &T)
{
	T = NULL;
	return OK;
}

void CreateBiTree(BiTree &T){
	SElemType data;
	std::cin >> data;
	if (data == '#') {
		T = NULL;
		return;
	}

	T = (BiTree)malloc(sizeof(BiTNode));
	if (!T) exit(OVERFLOW);
	T->data = data;
	CreateBiTree(T->lchild);
	CreateBiTree(T->rchild);
}

Status PreOrderTraverse_recur(BiTree &T, void(*visit)(SElemType)) {
	if (T)
	{
		visit(T->data); /* 先访问根结点 */
		PreOrderTraverse_recur(T->lchild, visit); /* 再先序遍历左子树 */
		PreOrderTraverse_recur(T->rchild, visit); /* 最后先序遍历右子树 */
	}
	return OK;
}

Status PreOrderTraverse(BiTree &T, void(*visit)(SElemType))
{ /* 初始条件: 二叉树T存在,Visit是对结点操作的应用函数 */
  /* 操作结果: 先序非递归遍历T,对每个结点调用函数Visit一次且仅一次 */
	BiTStack S;
	BiTNode* p;
	InitStack(S);
	p = T;
	while (p || !StackEmpty(S)) {
		if (p) {
			visit(p->data);
			Push(S, p);
			p = p->lchild;
		}
		else {
			Pop(S, &p);
			p = p->rchild;
		}
	}
	DestroyStack(S);
	return OK;
}

Status InOrderTraverse_recur(BiTree &T, void(*visit)(SElemType))
{ /* 初始条件: 二叉树T存在,Visit是对结点操作的应用函数 */
  /* 操作结果: 中序递归遍历T,对每个结点调用函数Visit一次且仅一次 */
	if (T)
	{
		InOrderTraverse_recur(T->lchild, visit); /* 先中序遍历左子树 */
		visit(T->data); /* 再访问根结点 */
		InOrderTraverse_recur(T->rchild, visit); /* 最后中序遍历右子树 */
	}
	return OK;
}

Status InOrderTraverse(BiTree &T, void(*visit)(SElemType))
{ /* 初始条件: 二叉树T存在,Visit是对结点操作的应用函数 */
  /* 操作结果: 中序非递归遍历T,对每个结点调用函数Visit一次且仅一次 */
	BiTStack S;
	BiTNode* p;
	InitStack(S);
	p = T;
	while (p || !StackEmpty(S)) {
		if (p) {
			Push(S, p);
			p = p->lchild;
		} else {
			Pop(S, &p);
			visit(p->data);
			p = p->rchild;
		}
	}
	DestroyStack(S);
	return OK;
}

Status PostOrderTraverse_recur(BiTree &T, void(*visit)(SElemType)) {
	if (T)
	{
		PostOrderTraverse_recur(T->lchild, visit); /* 再先序遍历左子树 */
		PostOrderTraverse_recur(T->rchild, visit); /* 最后先序遍历右子树 */
		visit(T->data); /* 先访问根结点 */
	}
	return OK;
}

Status PostOrderTraverse(BiTree &T, void(*visit)(SElemType))
{ 
	BiTStack S;
	InitStack(S);
	BiTNode **ptr;
	BiTNode **cur; //当前结点   
	BiTNode **pre = NULL; //前一次访问的结点
	Push(S, T); 
	while(!StackEmpty(S))
	{
		//ptr = S.top;
		//cur = --ptr;
		GetTop(S, &cur);
		if (((*cur)->lchild == NULL && (*cur)->rchild == NULL) || (pre != NULL && ((*pre) == (*cur)->lchild || *pre == (*cur)->rchild)))
		{
			std::cout << (*cur)->data; //如果当前结点没有孩子结点或者孩子节点都已被访问过
			pre = cur;
			Pop(S, cur);
		}
		else {
			if ((*cur)->rchild != NULL)
				Push(S, (*cur)->rchild);
			if ((*cur)->lchild != NULL)
				Push(S, (*cur)->lchild);
		}
	}
	DestroyStack(S);
	return OK;
}
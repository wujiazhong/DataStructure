#include "BiTree.h"
#include <iostream>

int main(int argc, char** argv) {
	BiTree T;
	InitBiTree(T);
	CreateBiTree(T);
	void(*pf)(SElemType);
	pf = visit;
	std::cout << "\nPreOrder: ";
	PreOrderTraverse(T, pf);
	std::cout << "\nPreOrder_recur: ";
	PreOrderTraverse_recur(T, pf);
	std::cout << "\nInOrder: ";
	InOrderTraverse(T, pf);
	std::cout << "\nInOrder_recur: ";
	InOrderTraverse_recur(T, pf);
	std::cout << "\nPostOrder: ";
	PostOrderTraverse(T, pf);
	std::cout << "\nPostOrder_recur: ";
	PostOrderTraverse_recur(T, pf);
	std::cout << "\n";
}
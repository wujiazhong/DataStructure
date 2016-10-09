#pragma once
#ifndef ELEMTYPE_H
#define ELEMTYPE_H

#include<string>

typedef struct {
	int val;
}ElemType;

int compare(ElemType , ElemType);
void visit(ElemType*);

#endif // !ELEMTYPE_H
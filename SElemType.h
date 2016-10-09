#pragma once
#ifndef SELEMTYPE_H
#define SELEMTYPE_H

typedef struct {
	int val;
}SElemType;

SElemType inline createSElemType(int val) {
	SElemType e;
	e.val = val;
	return e;
}

#endif // !SELEMTYPE_H
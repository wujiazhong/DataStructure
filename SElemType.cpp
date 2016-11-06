#include "SElemType.h"
#include <iostream>
SElemType createSElemType(SElemType val) {
	SElemType e;
	e = val;
	return e;
}

void visit(SElemType e) {
	std::cout << e;
}
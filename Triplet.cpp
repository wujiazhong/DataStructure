#include "Triplet.h"
#include <iostream>

Status InitTriplet(Triplet &T, int v1, int v2, int v3) {
	T = (int*)malloc(3 * sizeof(int));
	if (!T) exit(OVERFLOW);

	T[0] = v1, T[1] = v2, T[2] = v3;
	return OK;
}
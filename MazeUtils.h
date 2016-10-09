#pragma once
#ifndef MAZEUTILS_H
#define MAZEUTILS_H

#include "PosStack.h"

const int COL = 8;
const int ROW = 8;

int Pass(int maze[8][8], PosType pos);
void FootPrint(PosType pos);

#endif // !MAZEUTILS_H
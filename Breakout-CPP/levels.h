#ifndef LEVELS_H
#define LEVELS_H

#include "global.h"

// 0 = Blank
// 1 = Red
// 2 = Yellow
// 3 = Green
constexpr int LEVEL_1[GAME_ROWS][GAME_COLS] = {
	{0, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 2, 3, 1, 2, 3, 0},
	{0, 1, 2, 3, 1, 2, 3, 0},
	{0, 1, 2, 3, 1, 2, 3, 0},
	{0, 1, 2, 3, 1, 2, 3, 0},
	{0, 1, 2, 3, 1, 2, 3, 0},
	{0, 1, 2, 3, 1, 2, 3, 0},
	{0, 0, 0, 0, 0, 0, 0, 0}
};

#endif


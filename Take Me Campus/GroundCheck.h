#pragma once
#include "object.h"
#include <stdbool.h>

typedef struct  {
	float x;
	float y;
}XY;

typedef struct  {
	XY max;
	XY min;
}MMX;

bool DrawCheck(MMX a, MMX b);

void stage2_Colide_side(Player* player, Object* side);

void stage2_Colide0(MMX* platform);

void stage2_Colide1(MMX* platform);
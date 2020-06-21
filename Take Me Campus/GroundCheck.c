#pragma once
#include "GroundCheck.h"
#include "object.h"

bool DrawCheck(MMX a, MMX b)
{
	if (a.max.x < b.min.x || a.min.x > b.max.x) return 0;
	if (a.max.y < b.min.y || a.min.y > b.max.y) return 0;

	

	return 1;
}
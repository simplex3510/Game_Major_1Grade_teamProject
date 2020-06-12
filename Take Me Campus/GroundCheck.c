#pragma once
#include "GroundCheck.h"
#include "object.h"

bool DrawCheck(MMX a, MMX b)
{
	if (a.max.x < b.min.x || a.min.x > b.max.x) return 0;
	if (a.max.y < b.min.y || a.min.y > b.max.y) return 0;
	return 1;
}

//void stage2_Colide_side(Player* player, Object* side)
//{
//	if ((player->position.x == side->position.x) &&
//		(player->position.y > side->position.y)) {
//		player->position.x += 2;
//	}
//}
//
//// 절벽 위 충돌체
//void stage2_Colide0(MMX* platform)
//{
//	platform->min.x = 2;
//	platform->min.y = 27;
//	platform->max.x = 110;
//	platform->max.y = 29;
//}
//
//// 첫 번째 플랫폼 충돌체
//void stage2_Colide1(MMX* stage2_platform2)
//{
//	stage2_platform2->min.x = 26;
//	stage2_platform2->min.y = 23;
//	stage2_platform2->max.x = 32;
//	stage2_platform2->max.y = 23;
//
//
//}
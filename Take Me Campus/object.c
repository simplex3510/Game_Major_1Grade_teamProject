#include <string.h>
#include <malloc.h>
#include "object.h"

#pragma once
#pragma warning (disable:4996)

char PLAYER_STR[] = "●";
char POTAL_STR[] = "★";
char PLATFORM_STR[] = "■";

void player_init(Player* player)
{
	player->bounce.isJump = 1;
	player->bounce.jumpTime = 70 / 1000.0f;
	player->bounce.isTop = 0;

	player->position.x = 2;		// 플레이어 초기 좌표
	player->position.y = 39;
	
	strcpy(player->strobject, PLAYER_STR);

	return;
}

void potal_init(Object* potal, int stage)
{
	potal->position.x = 120;		// 플레이어 초기 좌표
	potal->position.y = 28;

	strcpy(potal->strobject, POTAL_STR);

	return;
}

void platform_init(Object* platfrom, int plus)
{
	platfrom->isColide = TRUE;
	platfrom->position.x = 112;
	platfrom->position.y = 29 - plus;

	strcpy(platfrom->strobject, PLATFORM_STR);

	return;
}

// 포탈 위치 
void potal_position(Object* potal, int stage)
{
	switch (stage)
	{
	case 1:
		potal->position.x = 120;
		potal->position.y = 28;
		break;
	case 2:
		potal->position.x = 120;
		potal->position.y = 5;
		break;
	case 3:
		potal->position.x = 2;
		potal->position.y = 29;
		break;
	case 4:
		potal->position.x = 1;	
		potal->position.y = 122;
		break;
	}

	return;
}
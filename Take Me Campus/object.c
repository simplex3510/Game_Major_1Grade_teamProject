#include <string.h>
#include <malloc.h>
#include "object.h"

#pragma once
#pragma warning (disable:4996)

char PLAYER_STR[] = "●";
char POTAL_STR[] = "★";

void player_init(Object* player)
{
	player->bounce.isJump = 1;
	player->bounce.jumpTime = 70;
	player->bounce.isTop = 0;

	player->position.x = 2;		// 플레이어 초기 좌표
	player->position.y = 39;
	
	strcpy(player->strobject, PLAYER_STR);

	return;
}

void potal_init(Object* potal, int stage)
{
	potal->position.x = 120;		// 플레이어 초기 좌표
	potal->position.y = 23;

	strcpy(potal->strobject, POTAL_STR);

	return;
}

// 포탈 위치 
void potal_position(Object* potal, int stage)
{
	switch (stage)
	{
	case 1:
		potal->position.x = 120;		// 플레이어 초기 좌표
		potal->position.y = 23;
		break;
	case 2:
		potal->position.x = 120;		// 플레이어 초기 좌표
		potal->position.y = 5;
		break;
	default:
		potal->position.x = 20;		// 플레이어 초기 좌표
		potal->position.y = 20;
		break;
	}

	return;
}

//void freeObject(Object* object)
//{
//	free(object->strobject);
//
//	return;
//}
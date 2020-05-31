#include <string.h>
#include <malloc.h>
#include "object.h"

#pragma once
#pragma warning (disable:4996)

char PLAYER_STR[] = "��";
char POTAL_STR[] = "��";
char platFORM_STR[] = "��";
char NIDDLE_STR[] = "��";


// �÷��̾� ��ü
void player_init(Player* player)
{
	//player->bounce.gravity = TRUE;
	player->bounce.isJump = TRUE;
	player->bounce.jumpTime = 100;
	player->bounce.isTop = FALSE;

	player->position.x = 2;		// �÷��̾� �ʱ� ��ǥ
	player->position.y = 29;
	
	strcpy(player->strobject, PLAYER_STR);

	return;
}

// ��Ż ��ü
void potal_init(Object* potal, int stage)
{
	potal->position.x = 120;		// �÷��̾� �ʱ� ��ǥ
	potal->position.y = 28;

	strcpy(potal->strobject, POTAL_STR);

	return;
}


void platform_init(Object* platfrom, int plus)
{
	platfrom->isColide = TRUE;
	platfrom->position.x = 112;
	platfrom->position.y = 29-plus;

	strcpy(platfrom->strobject, platFORM_STR);

	return;
}

void niddle_init()
{


}

// ������Ʈ ��ġ 
void object_position(Object* potal, Player* player, int stage)
{
	switch (stage)
	{
	case 1:
		potal->position.x = 120;		// �÷��̾� �ʱ� ��ǥ
		potal->position.y = 28;

		player->position.x = 2;
		player->position.y = 39;

		break;
	case 2:
		potal->position.x = 120;		// �÷��̾� �ʱ� ��ǥ
		potal->position.y = 5;

		player->position.x = 120;
		player->position.y = 29;

		break;
	default:
		potal->position.x = 20;		// �÷��̾� �ʱ� ��ǥ
		potal->position.y = 20;
		break;
	}

	return;
}
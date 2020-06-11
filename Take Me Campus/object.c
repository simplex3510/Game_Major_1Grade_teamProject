#include <string.h>
#include <malloc.h>
#include "object.h"

#pragma once
#pragma warning (disable:4996)

char PLAYER_STR[] = "��";
char POTAL_STR[] = "��";
char HOME_STR[] = "��";
char PLATFORM_STR[] = "��";

void player_init(Player* player)
{
	player->bounce.jumpTime = 50;	// �÷��̾� ���� �ð�
	player->bounce.isTop = 0;

	player->position.x = 2;		// �÷��̾� �ʱ� ��ǥ
	player->position.y = 39;
	
	strcpy(player->strobject, PLAYER_STR);

	return;
}

void potal_init(Object* potal, int stage)
{
	potal->position.x = 120;		// ��Ż �ʱ� ��ǥ
	potal->position.y = 28;

	strcpy(potal->strobject, POTAL_STR);

	return;
}

void home_init(Object* home)
{
	home->position.x = 122;		// ��Ż �ʱ� ��ǥ
	home->position.y = 0;

	strcpy(home->strobject, HOME_STR);

	return;
}

void side_init(Object* side, int plus)
{
	side->position.x = 110;
	side->position.y = 28 - plus;

	strcpy(side->strobject, PLATFORM_STR);

	return;
}

// ��Ż ��ġ 
void object_position(Player* player, Object* potal, Object* home, int stage)
{
	switch (stage)
	{
	case 1:
		potal->position.x = 120;
		potal->position.y = 28;

		home->position.x = 122;
		home->position.y = 0;
		break;
	case 2:
		potal->position.x = 122;
		potal->position.y = 5;

		home->position.x = 122;
		home->position.y = 0;
		break;
	case 3:
		potal->position.x = 2;
		potal->position.y = 29;

		player->position.x = 122;
		player->position.y = 9;

		home->position.x = 122;
		home->position.y = 29;
		break;
	case 4:
		potal->position.x = 64;	
		potal->position.y = 29;

		home->position.x = 122;
		home->position.y = 0;
		break;
	}

	return;
}
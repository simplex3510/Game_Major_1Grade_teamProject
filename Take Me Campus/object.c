#include <string.h>
#include <malloc.h>
#include "object.h"

#pragma once
#pragma warning (disable:4996)

char PLAYER_STR[] = "��";
char POTAL_STR[] = "��";

void player_init(Object* player)
{
	player->bounce.isJump = 1;
	player->bounce.jumpTime = 100;
	player->bounce.isTop = 0;

	player->position.x = 2;		// �÷��̾� �ʱ� ��ǥ
	player->position.y = 23;

	player->playerLen = strlen(PLAYER_STR);

	player->strPlayer = (char*)malloc(sizeof(char) * player->playerLen);
	strcpy(player->strPlayer, PLAYER_STR);

	return;
}

void potal_init(Object* potal, int stage)
{
	potal->position.x = 120;		// �÷��̾� �ʱ� ��ǥ
	potal->position.y = 23;

	potal->playerLen = strlen(POTAL_STR);

	potal->strPlayer = (char*)malloc(sizeof(char) * potal->playerLen);
	strcpy(potal->strPlayer, POTAL_STR);

	return;
}

// ��Ż ��ġ 
void potal_position(Object* potal, int stage)
{
	switch (stage)
	{
	case 1:
		potal->position.x = 120;		// �÷��̾� �ʱ� ��ǥ
		potal->position.y = 23;
		break;
	case 2:
		potal->position.x = 120;		// �÷��̾� �ʱ� ��ǥ
		potal->position.y = 5;
		break;
	default:
		potal->position.x = 20;		// �÷��̾� �ʱ� ��ǥ
		potal->position.y = 20;
		break;
	}

	return;
}

//void destroyObject(Object* object)
//{
//	free(object->strPlayer);
//
//	return;
//}
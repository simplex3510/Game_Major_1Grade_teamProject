#pragma once

typedef struct {
	int x, y;		// ������Ʈ ��ǥ
} Position;

typedef struct {
	Position position;		// ������Ʈ ��ǥ
	char* strPlayer;		// ������Ʈ ���ڿ�
	int playerLen;			// ������Ʈ ����
} Object;

void player_init(Object* player);

void potal_init(Object* potal, int stage);

//void destroyObject(Object* object);

//Player player;		// �÷��̾� ����
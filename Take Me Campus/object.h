#pragma once

typedef struct {
	int x, y;		// 오브젝트 좌표
} Position;

typedef struct {
	Position position;		// 오브젝트 좌표
	char* strPlayer;		// 오브젝트 문자열
	int playerLen;			// 오브젝트 길이
} Object;

void player_init(Object* player);

void potal_init(Object* potal, int stage);

//void destroyObject(Object* object);

//Player player;		// 플레이어 선언
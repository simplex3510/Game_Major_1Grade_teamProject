#include <time.h>

#pragma once

#define OBJECT_SIZE 3

typedef struct {
	int x, y;		// 오브젝트 좌표
} Position;

typedef struct {
	// 바운스 애니메이션 용
	int isJump;			// 공중에 뜬 상태인가 (0은 지면에 붙음, 1은 공중에 뜸)
	int isTop;
	clock_t jumpTime;	// 점프를 하고 있는 시간
	clock_t oldTime;	// 마지막으로 점프한 시간, 기준이 되는 시간
}Bounce;

typedef struct {

	Position position;					// 오브젝트 좌표
	char strobject[OBJECT_SIZE];		// 오브젝트 문자열과 크기, 예상 가능한 크기임으로 3 고정
	Bounce bounce;

} Object;

void player_init(Object* player);

void potal_init(Object* potal, int stage);

void potal_position(Object* potal, int stage);

void freeObject(Object* object);

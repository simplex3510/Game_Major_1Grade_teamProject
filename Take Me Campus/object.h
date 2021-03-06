#include <time.h>

#pragma once

#define JUMP_SIZE 3
#define OBJECT_SIZE 3

#define TRUE 1
#define FALSE 0

typedef struct {
	float x, y;		// 오브젝트 좌표
} Position;

typedef struct {
	// 바운스 애니메이션 용
	int isTop;
	clock_t jumpTime_high;	// 점프를 하고 있는 시간
	clock_t jumpTime_middle;	// 점프를 하고 있는 시간
	clock_t jumpTime_low;	// 점프를 하고 있는 시간
	clock_t oldTime;	// 마지막으로 점프한 시간, 기준이 되는 시간
}Bounce;


typedef struct {

	Position position;					// 오브젝트 좌표
	char strobject[OBJECT_SIZE];		// 오브젝트 문자열과 크기, 예상 가능한 크기임으로 3 고정
	Bounce bounce;						// 바운스 및 중력 관련 변수

} Player;

typedef struct {

	Position position;					// 오브젝트 좌표
	char strobject[OBJECT_SIZE];		// 오브젝트 문자열과 크기, 예상 가능한 크기임으로 3 고정
	int isColide;

} Object;


void player_init(Player* player);

void potal_init(Object* potal, int stage);

void home_init(Object* home);

void object_position(Player* player, Object* potal, Object* home, int stage);


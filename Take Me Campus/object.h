#include <time.h>

#pragma once

#define JUMP_SIZE 3
#define OBJECT_SIZE 3

#define TRUE 1
#define FALSE 0

typedef struct {
	float x, y;		// ������Ʈ ��ǥ
} Position;

typedef struct {
	// �ٿ �ִϸ��̼� ��
	int isTop;
	clock_t jumpTime_high;	// ������ �ϰ� �ִ� �ð�
	clock_t jumpTime_middle;	// ������ �ϰ� �ִ� �ð�
	clock_t jumpTime_low;	// ������ �ϰ� �ִ� �ð�
	clock_t oldTime;	// ���������� ������ �ð�, ������ �Ǵ� �ð�
}Bounce;


typedef struct {

	Position position;					// ������Ʈ ��ǥ
	char strobject[OBJECT_SIZE];		// ������Ʈ ���ڿ��� ũ��, ���� ������ ũ�������� 3 ����
	Bounce bounce;						// �ٿ �� �߷� ���� ����

} Player;

typedef struct {

	Position position;					// ������Ʈ ��ǥ
	char strobject[OBJECT_SIZE];		// ������Ʈ ���ڿ��� ũ��, ���� ������ ũ�������� 3 ����
	int isColide;

} Object;


void player_init(Player* player);

void potal_init(Object* potal, int stage);

void home_init(Object* home);

void side_init(Object* platfrom, int plus);

void object_position(Player* player, Object* potal, Object* home, int stage);


#include <time.h>

#pragma once

#define JUMP_SIZE 3
#define OBJECT_SIZE 3

#define TRUE 1
#define FALSE 0

typedef struct {
	int x, y;		// ������Ʈ ��ǥ
} Position;

typedef struct {
	// �ٿ �ִϸ��̼� ��
	int isJump;			// ���߿� �� �����ΰ� (0�� ���鿡 ����, 1�� ���߿� ��)
	int isTop;
	clock_t jumpTime;	// ������ �ϰ� �ִ� �ð�
	clock_t oldTime;	// ���������� ������ �ð�, ������ �Ǵ� �ð�

	// �߷°� ��� ����

	int gravity;

}Physics;


typedef struct {

	Position position;					// ������Ʈ ��ǥ
	char strobject[OBJECT_SIZE];		// ������Ʈ ���ڿ��� ũ��, ���� ������ ũ�������� 3 ����
	Physics bounce;						// �ٿ �� �߷� ���� ����

} Player;

typedef struct {

	Position position;					// ������Ʈ ��ǥ
	char strobject[OBJECT_SIZE];		// ������Ʈ ���ڿ��� ũ��, ���� ������ ũ�������� 3 ����
	int isColide;

} Object;


void player_init(Player* player);

void potal_init(Object* potal, int stage);

void platform_init(Object* platfrom);

void niddle_init();

void object_position(Object* potal, Player* player, int stage);


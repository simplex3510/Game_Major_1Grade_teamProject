#include <time.h>

#pragma once

#define OBJECT_SIZE 3

typedef struct {
	int x, y;		// ������Ʈ ��ǥ
} Position;

typedef struct {
	// �ٿ �ִϸ��̼� ��
	int isJump;			// ���߿� �� �����ΰ� (0�� ���鿡 ����, 1�� ���߿� ��)
	int isTop;
	clock_t jumpTime;	// ������ �ϰ� �ִ� �ð�
	clock_t oldTime;	// ���������� ������ �ð�, ������ �Ǵ� �ð�
}Bounce;

typedef struct {

	Position position;					// ������Ʈ ��ǥ
	char strobject[OBJECT_SIZE];		// ������Ʈ ���ڿ��� ũ��, ���� ������ ũ�������� 3 ����
	Bounce bounce;

} Object;

void player_init(Object* player);

void potal_init(Object* potal, int stage);

void potal_position(Object* potal, int stage);

void freeObject(Object* object);

#pragma warning (disable:4996)

#include <stdio.h>			// ǥ�� ����� ���
#include <conio.h>			// �����, ǥ�ؿ��� ���

#include "screen.h"			// ������ ó�� ���
#include "colide.h"			// �������� �� �浹 üũ
#include "maps.h"
#include "object.h"
#include "SoundManager.h"


#define TRUE 1
#define ESC 27

#define ARROW 224
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77


Player player;		// �÷��̾� ������Ʈ ����
Object potal;		// ��Ż ������Ʈ ����
Object platform[5];

static int stage = 1;


void init()
{
	player_init(&player);		// �÷��̾� �ʱ�ȭ
	potal_init(&potal, stage);	// ��Ż �ʱ�ȭ
	for (int i = 0; i < 3; i++)
	{
		platform_init(&platform[i], i);
	}
	sound_init();				// FMOD �ʱ�ȭ
	playBgmSound(1);			// 1��° ��� ����
	sound_volume(0.1f);
}

void update()
{
	clock_t curTime = clock();
	static int count = 0;
	player.bounce.isJump = 1;

	// ��, �ֱ� �ð��� ���� �ð��� ���� �ð����� �����µ�, �̰� ���� ���غ��� Ŀ����
	// -> ������ ���� ������ �ð��� ���� = ���� �ӵ�
	// ������ ���������� �ð��� < (�ֱٽð� - ���� �ð�)
	while (player.bounce.jumpTime < (curTime - player.bounce.oldTime)) {

		// �ְ����� �ƴ϶��, ����Ѵ�.
		if (player.bounce.isTop == 0) {
			player.position.y--;
			count++;
			// �ְ����� �ٶ��� ���, 
			if (count == 3) { player.bounce.isTop = 1; }
			player.bounce.oldTime = curTime;	// ���� ���� �ð� ������Ʈ

			return;
		}
		// �ְ����̶��, �ϰ��Ѵ�.
		else if (player.bounce.isTop == 1) {
			player.position.y++;
			count++;
			// �ٽ� �������� ���
			if (count == 6) { player.bounce.isTop = 0; player.bounce.isJump = 0; count = 0; }
			player.bounce.oldTime = curTime;	// ���� ���� �ð� ������Ʈ
			return;
		}
	}
}

// ȭ�鿡 ���
void render()
{
	screenClear();

	char string[100] = { 0, };

	// ��Ż �浹 üũ, ���� ��������
	if ((player.position.x == potal.position.x) &&
		(player.position.y == potal.position.y)) {
		stage++;
		potal_position(&potal, stage);
	}

	sprintf(string, "ĳ���� �̵� ��ǥ: (%d, %d)", player.position.x, player.position.y);

	// �������� ���
	switch (stage)
	{
	case 1:
		stage1();
		break;
	case 2:
		stage2();
		for (int i = 0; i < 3; i++) {
			screenPrint(platform[i].position.x, platform[i].position.y, platform[i].strobject);
			stage2Colide(&player, &platform[i]);
		}
		break;
	default:
		stage1();
		break;
	}

	// �������� ����� ��� - Ŭ���� ��� Ȱ��
	if (player.position.x < 2) {
		screenPrint(2, player.position.y, player.strobject);
		player.position.x = 2;
	}
	// ���������� ����� ���
	else if (122 < player.position.x) {
		screenPrint(122, player.position.y, player.strobject);
		player.position.x = 122;
	}
	// �Ʒ������� ����� ���
	else if (29 < player.position.y) {
		screenPrint(player.position.x, 29, player.strobject);
		player.position.y = 29;
	}
	// �������� ����� ���
	else if (player.position.y < 2) {
		screenPrint(player.position.x, 2, player.strobject);
		player.position.y = 2;
	}
	// �Ϲ� ������
	else {
		screenPrint(potal.position.x, potal.position.y, potal.strobject);		// ��Ż ������
		screenPrint(player.position.x, player.position.y, player.strobject);	// �÷��̾� ������
	}

	screenPrint(10, 0, string);
	screenFlipping();
}

// ���� �Ҵ� ����
void release()
{

}

// ������ ����
void waitRender(clock_t oldTime)
{
	clock_t curTime;
	while (TRUE) {

		curTime = clock();					// ���� ���� �ð��� ���������� ����
		if (10 < curTime - oldTime)			// �� �ð��� ���� (16ms - 60 fps) or (33ms - 30fps)�� �� ������ Ż��, 10�����ϴϱ� 60������
			break;
	}
}

// Ű �ν�
int getKeyEvent()
{
	int key1, key2;

	if (_kbhit()) {						// Ű���� �Է� �ν�
		key1 = _getch();				// ����Ű ù ��° �ƽ�Ű �ڵ� �� ����

		if (key1 == ESC)					// escŰ �Է�

			return key1;				// �ش� Ű���� �� ��ȯ

		key2 = _getch();				// ����Ű �� ��° �ƽ�Ű �ڵ� �� ����
		if (key1 == ARROW)				// ����Ű�� �ԷµǾ��� ��
			return key1, key2;			// ����Ű �Է°� ��ȯ
	}

	return -1;						// ����Ű �Է��� �ƴϸ� -1 ��ȯ
}

// �νĵ� Ű�� �����ϴ� ��� ����
void keyProcess(int key2)
{

	switch (key2) {					// ���� ���� ����Ű ���̽� ����
	case UP:
		//printf("��");
		player.position.y -= 1;
		break;
	case DOWN:
		//printf("��");
		player.position.y += 1;
		break;
	case LEFT:
		//printf("��");
		player.position.x -= 2;
		break;
	case RIGHT:
		//printf("��");
		player.position.x += 2;
		break;
	}
}

int main()
{
	screenInit();	// ��ũ�� �ʱ�ȭ
	init();			// ���� �ʱ�ȭ
	

	int nKey;

	// ���� ����
	while (TRUE) {

		nKey = getKeyEvent();
		if (nKey == 27)		// ESC �Է�
			break;				// �ݺ� Ż�� ��, ���� ����

		keyProcess(nKey);		// Ű ���μ��� ����

		update();				// ������ ������Ʈ

		sound_update();			//FMOD ������Ʈ

		render();				// �׷��� ������
		waitRender(clock());
	}

	release();					// �����Ҵ� ����
	screenRelease();			// ��ũ�� ���� �Ҵ� ����
	sound_release();			// FMOD ����

	printf("Thank you for your playing!");

	return 0;
}
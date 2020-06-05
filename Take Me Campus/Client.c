#pragma warning (disable:4996)

#include <stdio.h>			// ǥ�� ����� ���
#include <conio.h>			// �����, ǥ�ؿ��� ���

#include "screen.h"			// ������ ó�� ���
#include "colide.h"			// �������� �� �浹 üũ
#include "maps.h"
#include "object.h"
#include "SoundManager.h"
#include "Timer.h"


#define TRUE 1
#define ESC 27

#define ARROW 224
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

int LOOP = TRUE;

clock_t curTime;
clock_t oldTime;

Player player;		// �÷��̾� ������Ʈ ����
Object potal;		// ��Ż ������Ʈ ����
//Object platform[5];

static int stage = 1;


void init()
{
	player_init(&player);		// �÷��̾� �ʱ�ȭ
	potal_init(&potal, stage);	// ��Ż �ʱ�ȭ
	/*for (int i = 0; i < 3; i++)
	{
		platform_init(&platform[i], i);
	}*/

	//initTimer();				// Ÿ�̸� �ʱ�ȭ

	sound_init();				// FMOD �ʱ�ȭ
}

void update()
{
	curTime = clock() / 1000.0f;
	static int count = 0;
	//player.bounce.isJump = 1;

	int speed = 3;
	float dist = 1;

	// ��, �ֱ� �ð��� ���� �ð��� ���� �ð����� �����µ�, �̰� ���� ���غ��� Ŀ����
	// -> ������ ���� ������ �ð��� ���� = ���� �ӵ�
	// ������ ���������� �ð��� < (�ֱٽð� - ���� �ð�)

	//updateTimer();

	//while (player.bounce.jumpTime < (curTime - player.bounce.oldTime)) {
	//
	//	// �ְ����� �ƴ϶��, ����Ѵ�.
	//	if (player.bounce.isTop == 0) {
	//		player.position.y--;
	//		count++;
	//		// �ְ����� �ٶ��� ���, 
	//		if (count == 3) { player.bounce.isTop = 1; }
	//		player.bounce.oldTime = curTime;	// ���� ���� �ð� ������Ʈ
	//
	//		return;
	//	}
	//	// �ְ����̶��, �ϰ��Ѵ�.
	//	else if (player.bounce.isTop == 1) {
	//		player.position.y++;
	//		count++;
	//		// �ٽ� �������� ���
	//		if (count == 6) { player.bounce.isTop = 0; player.bounce.isJump = 0; count = 0; }
	//		player.bounce.oldTime = curTime;	// ���� ���� �ð� ������Ʈ
	//		return;
	//	}
	//}

	//while (player.bounce.jumpTime < (curTime - player.bounce.oldTime))
	while (player.bounce.jumpTime < (curTime - oldTime)*1) {

		dist = speed * ((curTime - oldTime) * 1);

		// �ְ����� �ƴ϶��, ����Ѵ�.
		if (player.bounce.isTop == 0) {
			player.position.y -= dist;
			count++;
			// �ְ����� �ٶ��� ���, 
			if (count == 3) { player.bounce.isTop = 1; }
			oldTime = curTime;    // ���� ���� �ð� ������Ʈ

			return;
		}
		// �ְ����̶��, �ϰ��Ѵ�.
		else if (player.bounce.isTop == 1) {
			player.position.y += dist;
			count++;
			// �ٽ� �������� ���
			if (count == 6) { player.bounce.isTop = 0; count = 0; }
			oldTime = curTime;    // ���� ���� �ð� ������Ʈ

			return;
		}
	}
}

// ȭ�鿡 ���
void render()
{
	// ȭ���� �ٽ� �׸��� ���� ����
	screenClear();

	char string[100] = { 0, };

	// ��Ż �浹 üũ, ���� ��������
	if ((player.position.x == potal.position.x) &&
		(player.position.y == potal.position.y)) {
		stage++;
		potal_position(&potal, stage);
	}

	// �������� ���
	switch (stage)
	{
	case 1:
		stage1();
		break;
	case 2:
		stage2();
		/*for (int i = 0; i < 3; i++) {
			screenPrint(platform[i].position.x, platform[i].position.y, platform[i].strobject);
			stage2Colide(&player, &platform[i]);
		}*/
		break;
	/*case 3:
		stage3();
		break;*/
	case 4:
		stageEnding();
		LOOP = FALSE;
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

	sprintf(string, "ĳ���� �̵� ��ǥ: (%f, %f)", player.position.x, player.position.y);
	screenPrint(0, 0, string);

	// ��ũ�� ���� ��ȯ
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



		// --------------����Ű ��---------------
		key2 = _getch();				// ����Ű �� ��° �ƽ�Ű �ڵ� �� ����
		if (key1 == ARROW)				// ����Ű�� �ԷµǾ��� ��
			return key2;				// ����Ű �Է°� ��ȯ
	}

	return -1;						// ����Ű �Է��� �ƴϸ� -1 ��ȯ
}

// �νĵ� Ű�� �����ϴ� ��� ����
void keyProcess(int key)
{

	switch (key) {					// ���� ���� ����Ű ���̽� ����
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
	playBgmSound(1);			// 1��° ��� ����
	sound_bgmVolume(0.1f);		// ����� ���� 0,1�� ����

	int nKey;

	// ���� ����
	while (LOOP) {

		nKey = getKeyEvent();
		if (nKey == ESC) {		// ESC �Է�

			break;				// �ݺ� Ż�� ��, ���� ����
		}

		keyProcess(nKey);		// Ű ���μ��� ����

		update();				// ������ ������Ʈ

		sound_update();			// FMOD ������Ʈ

		render();				// �׷��� ������
		waitRender(clock());
	}

	release();					// �����Ҵ� ����
	screenRelease();			// ��ũ�� ����
	sound_release();			// FMOD ����

	printf("Thank you for your playing!");

	return 0;
}
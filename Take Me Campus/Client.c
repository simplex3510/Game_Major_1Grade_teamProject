#include <stdio.h>			// ǥ�� ����� ���
#include <conio.h>			// �����, ǥ�ؿ��� ���

#include "fps.h"			// fps ��� ���
#include "screen.h"			// ������ ó�� ���
#include "object.h"
#include "colide.h"

#pragma warning (disable:4996)

#define TRUE 1
#define FALSE 0

#define ESC 27
#define ARROW 224
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77


FPSData* fpsData;	// fpsData�� FPSData ������ �������� ���� 

Player player;		// �÷��̾� ������Ʈ ����
Object potal;		// ��Ż ������Ʈ ����
Object platform[5];

static int stage = 1;


void init()
{
	initFPSData(&fpsData);		// FPS �ʱ�ȭ
	player_init(&player);		// �÷��̾� �ʱ�ȭ
	potal_init(&potal, stage);	// ��Ż �ʱ�ȭ
	for (int i = 0; i < 3; i++)
	{
		platform_init(&platform[i], i);
	}

}

// ���� ������ ������Ʈ
void update()
{
	clock_t curTime = clock();
	static int count = 0;
	player.bounce.isJump = 1;

	if (player.bounce.isJump == TRUE) {
		while (player.bounce.jumpTime < (curTime - player.bounce.oldTime)) {
			bounce(&player, &platform);
		}
	}


}

// ȭ�鿡 ���
void render()
{
	screenClear();
	drawFPS(&fpsData);

	char string[100] = { 0, };

	// ��Ż �浹 üũ, ���� ��������
	if ((player.position.x == potal.position.x) &&
		(player.position.y == potal.position.y)) {
		stage++;
		object_position(&potal, &player, stage);
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
		/*for (int i = 0; i < 3; i++){
			screenPrint(platform[i].position.x, platform[i].position.y, platform[i].strobject);
			stage2Colide(&player, &platform[i]);
		}*/
		break;
	default:
		stage1();
		break;
	}

	wallColide(&player);												// �ܰ� �� �浹üũ

	screenPrint(potal.position.x, potal.position.y, potal.strobject);		// ��Ż ������

	screenPrint(player.position.x, player.position.y, player.strobject);	// �÷��̾� ������

	screenPrint(10, 0, string);
	screenFlipping();
}

// ���� �Ҵ� ����
void release()
{
	// FPS ���� �����Ҵ� 2�� ����
	freeFPSData(&fpsData);

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

		render();				// �׷��� ������

		waitRender(clock());	// ������ �� ����
	}

	release();					// �����Ҵ� ����
	screenRelease();			// ��ũ�� ���� �Ҵ� ����

	printf("Thank you for your playing!");

	return 0;
}
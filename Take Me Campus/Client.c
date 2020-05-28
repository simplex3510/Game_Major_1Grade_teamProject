#include <stdio.h>			// ǥ�� ����� ���
#include <time.h>			// �ð��� ���õ� �Լ� ���
#include <conio.h>			// �����, ǥ�ؿ��� ���
#include <string.h>

#include "fps.h"			// fps ��� ���
#include "screen.h"			// ������ ó�� ���
#include "maps.h"
#include "object.h"

#pragma warning (disable:4996)

#define TRUE 1

FPSData* fpsData;	//

Object player;
Object potal;

static stage = 1;


void init()
{
	initFPSData(&fpsData);
	player_init(&player);		// �÷��̾� �ʱ�ȭ
	potal_init(&potal, stage);
}

void update()
{

}

void render()
{
	screenClear();
	drawFPS(&fpsData);

	char string[100] = { 0, };
	static stage = 1;

	// �������� Ŭ����
	if ((player.position.x == potal.position.x) &&
		(player.position.y == potal.position.y)) {
		stage++;
		potal_init(&potal, stage);
	}

	sprintf(string, "ĳ���� �̵� ��ǥ: (%d, %d)", player.position.x, player.position.y);
	
	switch (stage)
	{
	case 1:
		stage1();
		break;
	case 2:
		stage2();
		break;
	default:
		stage1();
		break;
	}

	// �������� ����� ��� - Ŭ���� ��� Ȱ��
	if (player.position.x < 2) {
		screenPrint(2, player.position.y, player.strPlayer);
		player.position.x = 2;
	}
	// ���������� ����� ���
	else if (122 < player.position.x) {
		screenPrint(122, player.position.y, player.strPlayer);
		player.position.x = 122;
	}
	// �Ʒ������� ����� ���
	else if (29 < player.position.y) {
		screenPrint(player.position.x, 29, player.strPlayer);
		player.position.y = 29;
	}
	// �������� ����� ���
	else if (player.position.y < 2) {
		screenPrint(player.position.x, 2, player.strPlayer);
		player.position.y = 2;
	}
	// �Ϲ� ������
	else {
		screenPrint(potal.position.x, potal.position.y, potal.strPlayer);
		screenPrint(player.position.x, player.position.y, player.strPlayer);
	}
	
	screenPrint(10, 0, string);
	screenFlipping();
}

// ���� �Ҵ� ����
void release()
{
	destoyFPSData(&fpsData);



	// ĳ����, ��Ż, 
	
}

void waitRender(clock_t oldTime)
{
	clock_t curTime;
	while (TRUE) {

		curTime = clock();					// ���� ���� �ð��� ���������� ����
		if (16 < curTime - oldTime)			// �� �ð��� ���� (16ms - 60 fps) or (33ms - 30fps)�� �� ������ Ż��
			break;
	}
}

int getKeyEvent()
{
	int key1, key2;
	if (_kbhit()) {					// Ű���� �Է� �ν�
		key1 = _getch();			// ����Ű ù ��° �ƽ�Ű �ڵ� �� ����

		if (key1 == 27)			// escŰ �Է�
			return key1;		// �ش� Ű���� �� ��ȯ

		key2 = _getch();		// ����Ű �� ��° �ƽ�Ű �ڵ� �� ����
		if (key1 == 224)			// ����Ű�� �ԷµǾ��� ��
			return key1, key2;			// ����Ű �Է°� ��ȯ
		
			
	}

	return -1;						// ����Ű �Է��� �ƴϸ� -1 ��ȯ
}

void keyProcess(int key2)
{

	switch (key2) {					// ���� ���� ����Ű ���̽� ����
	case 80:
		printf("��");
		player.position.y += 1;
		break;
	case 72:
		printf("��");
		player.position.y -= 1;
		break;
	case 75:
		//printf("��");
		player.position.x -= 2;
		break;
	case 77:
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

	while (TRUE) {
		
		nKey = getKeyEvent();
		if (nKey == 27)		// ESC �Է�
			break;				// �ݺ� Ż�� ��, ���� ����

		keyProcess(nKey);		// Ű ���μ��� ����

		update();				// ������ ������Ʈ

		render();				// �׷��� ������
		waitRender(clock());
	}

	release();					// �����Ҵ� ����
	screenRelease();			// ��ũ�� ���� �Ҵ� ����

	return 0;
}
#include <stdio.h>			// ǥ�� ����� ���
#include <time.h>			// �ð��� ���õ� �Լ� ���
#include <conio.h>			// �����, ǥ�ؿ��� ���
#include <string.h>

#include "fps.h"			// fps ��� ���
#include "screen.h"			// ������ ó�� ���

#pragma warning (disable:4996)

#define TRUE 1

FPSData* fpsData;

char PLAYER_STR[] = "��";

typedef struct {
	int x, y;
} Position;

typedef struct {
	Position position;
	char* strPlayer;
	int playerLen;
} Player;

Player player;

void init()
{
	initFPSData(&fpsData);
	player.position.x = 1;
	player.position.y = 22;

	player.playerLen = strlen(PLAYER_STR);

	player.strPlayer = (char*)malloc(sizeof(char) * player.playerLen);
	strcpy(player.strPlayer, PLAYER_STR);
}

void update()
{

}

void render()
{
	screenClear();
	drawFPS(&fpsData);

	char string[100] = { 0, };

	screenPrint(player.position.x, player.position.y, player.strPlayer);



	sprintf(string, "ĳ���� �̵� ��ǥ: (%d, %d)", player.position.x, player.position.y);
	screenPrint(0, 3, string);
	screenFlipping();
}

// ���� �Ҵ� ����
void release()
{
	destoyFPSData(&fpsData);
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

		keyProcess(nKey);		// 


		update();				// ������ ������Ʈ

		render();				// �׷��� ������
		waitRender(clock());
	}

	release();					// �����Ҵ� ����
	screenRelease();			// ��ũ�� ���� �Ҵ� ����

	/*system("cls");
	system("title Take Me Campus");
	system("mode con cols=122 lines=40");
	system("color F0");

	stage1();

	input_key();


	return 0;*/

	return 0;
}
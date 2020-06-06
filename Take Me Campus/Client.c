#pragma once
#pragma warning (disable:4996)

#include <stdio.h>			// ǥ�� ����� ���
#include <conio.h>			// �����, ǥ�ؿ��� ���

#include "screen.h"			// ������ ó�� ���
#include "maps.h"
#include "object.h"
#include "SoundManager.h"
#include "GroundCheck.h"


#define TRUE 1
#define ESC 27

#define ARROW 224
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

int LOOP = TRUE;
int isColide = FALSE;
int* isColide_ptr = &isColide;

clock_t curTime;
clock_t oldTime;

Player player;		// �÷��̾� ������Ʈ ����
Object potal;		// ��Ż ������Ʈ ����
Object home;
Object side[3];

MMX player_check;
MMX platform;
MMX fence;

MMX platform_stage2_2;

static int stage = 1;



void init()
{
	player_init(&player);		// �÷��̾� �ʱ�ȭ
	potal_init(&potal, stage);	// ��Ż �ʱ�ȭ
	home_init(&home);

	sound_init();				// FMOD �ʱ�ȭ
	
	for (int i = 0; i < 3; i++)
		side_init(&side[i], i);

	// �� ������ �浹ü
	fence.max.x = 122;	fence.max.y = 29;
	fence.min.x = 2;	fence.min.y = 29;
	DrawCheck(player_check, fence);

}

void update()
{
	clock_t curTime = clock();
	static int count = 0;

	// ��, �ֱ� �ð��� ���� �ð��� ���� �ð����� �����µ�, �̰� ���� ���غ��� Ŀ����
	// -> ������ ���� ������ �ð��� ���� = ���� �ӵ�
	// ������ ���������� �ð��� < (�ֱٽð� - ���� �ð�)

	//while (player.bounce.jumpTime < (curTime - player.bounce.oldTime)) {
	//
	//	// �ְ����� �ƴ϶��, ����Ѵ�.
	//	if ((player.bounce.isTop == 0) || (*isColide_ptr == TRUE)) {
	//		player.position.y--;
	//		count++;
	//		// �ְ����� �ٶ��� ���, 
	//		if (count == 3) { player.bounce.isTop = 1; }
	//		player.bounce.oldTime = curTime;	// ���� ���� �ð� ������Ʈ
	//
	//		return;
	//	}
	//	// �ְ����̶��, �ϰ��Ѵ�.
	//	else if ((player.bounce.isTop == 1) || (*isColide_ptr == FALSE)) {
	//		player.position.y++;
	//		count++;
	//		// �ٽ� �������� ���
	//		if (count == 6) { player.bounce.isTop = 0; count = 0; }
	//		player.bounce.oldTime = curTime;	// ���� ���� �ð� ������Ʈ
	//		return;
	//	}
	//}

	while (player.bounce.jumpTime < (curTime - player.bounce.oldTime)) {

		// �ְ����� �ƴ϶��, ����Ѵ�.
		if ( (TRUE <= *isColide_ptr) && (*isColide_ptr <= 4) ) {
			player.position.y--;
			(*isColide_ptr)++;
			// �ְ����� �ٶ��� ���, 
			if (*isColide_ptr == 4) {
				*isColide_ptr = FALSE;
			}
			player.bounce.oldTime = curTime;	// ���� ���� �ð� ������Ʈ

			return;
		}
		// �ְ����̶��, �ϰ��Ѵ�.
		else if ( (*isColide_ptr == FALSE) ) {
			player.position.y++;
			// �ٽ� �������� ���
			//if (*isColide_ptr == TRUE) { player.bounce.isTop = 0; count = 0; }
			player.bounce.oldTime = curTime;	// ���� ���� �ð� ������Ʈ
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
	char str_stage[50] = { 0, };
	char str_colide[20] = { 0, };

	player_check.min.x = player.position.x;
	player_check.min.y = player.position.y;
	player_check.max.x = player.position.x + 1;
	player_check.max.y = player.position.y;

	// ��Ż �浹 üũ, ���� ��������
	if ((player.position.x == potal.position.x) &&
		(player.position.y == potal.position.y)) {
		stage++;
		object_position(&player, &potal, &home, stage);

	}
	else if ((player.position.x == home.position.x) &&
			 (player.position.y == home.position.y)) {
		stage++;
		object_position(&player, &potal, &home, stage);
	}

	// �������� ���
	switch (stage)
	{
	case 1:
		stage1();

		if (DrawCheck(player_check, fence) == true)
			*isColide_ptr = TRUE;

		break;
	case 2:
		stage2();

		// ���� ���κ� ���Ƴ���
		stage2_Colide_side(&player, &side[0]);
		stage2_Colide_side(&player, &side[1]);
		stage2_Colide_side(&player, &side[2]);

		// ���� �� �浹ü
		stage2_Colide0(&platform);

		// ù ��° �÷��� �浹ü
		stage2_Colide1(&platform_stage2_2);

		DrawCheck(player_check, platform_stage2_2);
		if (DrawCheck(player_check, platform_stage2_2) == true)
			*isColide_ptr = TRUE;


		DrawCheck(player_check, platform);
		if (DrawCheck(player_check, platform) == true) 
			*isColide_ptr = TRUE;

		DrawCheck(player_check, fence);
		if (DrawCheck(player_check, fence) == true)
			*isColide_ptr = TRUE;

		break;

	case 3:
		stage3(&platform);

		DrawCheck(player_check, platform);
		if (DrawCheck(player_check, platform) == true)
			*isColide_ptr = TRUE;

		DrawCheck(player_check, fence);
		if (DrawCheck(player_check, fence) == true)
			*isColide_ptr = TRUE;

		break;

	case 4:
		stageEnding(&platform);

		DrawCheck(player_check, platform);
		if (DrawCheck(player_check, platform) == true)
			*isColide_ptr = TRUE;

		DrawCheck(player_check, fence);
		if (DrawCheck(player_check, fence) == true)
			*isColide_ptr = TRUE;

		break;

	default:
		stage1();
		LOOP = FALSE;
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
		screenPrint(home.position.x, home.position.y, home.strobject);			// Ȩ ������
		screenPrint(potal.position.x, potal.position.y, potal.strobject);		// ��Ż ������
		screenPrint(player.position.x, player.position.y, player.strobject);	// �÷��̾� ������
	}


	sprintf(str_colide, "�浹: %d", isColide);
	screenPrint(70, 0, str_colide);
	sprintf(str_stage, "��������: %d", stage);
	screenPrint(50, 0, str_stage);
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
	while (TRUE) {

		curTime = clock();			// ���� ���� �ð��� ���������� ����
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
		waitRender(oldTime);
	}

	release();					// �����Ҵ� ����
	screenRelease();			// ��ũ�� ����
	sound_release();			// FMOD ����

	printf("Thank you for your playing!");

	return 0;
}


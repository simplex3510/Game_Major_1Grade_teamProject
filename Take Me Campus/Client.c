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

int isTrapped = FALSE;
int* isTrapped_ptr = &isTrapped;

int isWallHitR = FALSE;
int* isWallHitR_ptr = &isWallHitR;

int isWallHitL = FALSE;
int* isWallHitL_ptr = &isWallHitL;

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

void addDrawCheck(MMX * a,float mx,float my,float Mx)
{
	a->max.x = Mx;
	a->max.y = my + 1;
	a->min.x = mx;
	a->min.y = my;
}

void addDrawCheck(MMX* a, float mx, float my,float My)
{
	a->max.x = mx;
	a->max.y = My;
	a->min.x = mx;
	a->min.y = my;
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

	if (*isWallHitL_ptr == true)
	{
		player.position.x--;
	}
	
	if (*isWallHitR_ptr == true)
	{
		player.position.x++;
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

	if (*isTrapped_ptr==true) {
		stage = 1;
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

		MMX wcs, cl, f, sos, Iic, bscegh, dywgtc;
		

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

		addDrawCheck(&wcs, 12.5, 23.5, 16.5);
		addDrawCheck(&cl, 5, 20.5, 13);
		addDrawCheck(&f, 15, 17.5, 23);
		addDrawCheck(&sos, 25, 14.5, 33);
		addDrawCheck(&Iic, 35, 11.5, 43);
		addDrawCheck(&bscegh, 45, 8.5, 53);
		addDrawCheck(&dywgtc, 55,5.5, 60);

		break;

	case 3:
		stage3(&platform);

		MMX a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v;
		MMX t1, t2, t3, t4, t5, t6, t7, t8;
		MMX w1, w2, w3, w4, w5, w6, w7, w8, w9, w10, w11, w12, w13, w14, w15, w16;


		DrawCheck(player_check, platform);
		if (DrawCheck(player_check, platform) == true)
			*isColide_ptr = TRUE;

		DrawCheck(player_check, fence);
		if (DrawCheck(player_check, fence) == true)
			*isColide_ptr = TRUE;

		/*�� �̵� �� Ʈ�� �浹 ���� �߰�*/
		{addDrawCheck(&a, 104, 29, 122);

		addDrawCheck(&t1, 100, 29, 102);

		addDrawCheck(&b, 88, 29, 98);
		addDrawCheck(&c, 80, 26, 86);

		addDrawCheck(&t2, 78, 29, 78);

		addDrawCheck(&d, 52, 29, 76);
		addDrawCheck(&e, 44, 26, 50);
		addDrawCheck(&f, 36, 23, 42);
		addDrawCheck(&g, 28, 20, 40);
		addDrawCheck(&h, 44, 18, 48);
		addDrawCheck(&i, 50, 16, 64);

		addDrawCheck(&t3, 66, 16, 68);
		addDrawCheck(&j, 70, 16, 78);
		addDrawCheck(&t4, 80, 16, 82);
		addDrawCheck(&k, 84, 16, 92);
		addDrawCheck(&t5, 94, 16, 96);
		addDrawCheck(&l, 98, 16, 122);


		addDrawCheck(&m, 116, 12, 122);
		addDrawCheck(&n, 104, 8, 110);
		addDrawCheck(&o, 52, 7, 102);
		addDrawCheck(&t6, 48, 7, 50);
		addDrawCheck(&p, 12, 7, 46);

		addDrawCheck(&q, 8, 13, 10);
		addDrawCheck(&t7, 4, 13, 6);
		addDrawCheck(&r, 2, 13, 2);

		addDrawCheck(&s, 8, 18, 18);

		addDrawCheck(&t, 2, 24, 6);
		addDrawCheck(&t8, 8, 24, 10);
		addDrawCheck(&u, 12, 24, 12);
		
		addDrawCheck(&v, 2, 29, 18);
		}

		/*�� �̵� �� Ʈ�� �浹 �Լ� ����*/
		{
			if (DrawCheck(player_check, a) == true)
				*isColide_ptr = TRUE;

			if (DrawCheck(player_check, t1) == true)
				*isTrapped_ptr = TRUE;

			if (DrawCheck(player_check, b) == true)
				*isColide_ptr = TRUE;
			if (DrawCheck(player_check, c) == true)
				*isColide_ptr = TRUE;

			if (DrawCheck(player_check, t2) == true)
				*isTrapped_ptr = TRUE;

			if (DrawCheck(player_check, d) == true)
				*isColide_ptr = TRUE;
			if (DrawCheck(player_check, e) == true)
				*isColide_ptr = TRUE;
			if (DrawCheck(player_check, f) == true)
				*isColide_ptr = TRUE;
			if (DrawCheck(player_check, g) == true)
				*isColide_ptr = TRUE;
			if (DrawCheck(player_check, h) == true)
				*isColide_ptr = TRUE;
			if (DrawCheck(player_check, i) == true)
				*isColide_ptr = TRUE;

			if (DrawCheck(player_check, t3) == true)
				*isTrapped_ptr = TRUE;
			if (DrawCheck(player_check, j) == true)
				*isColide_ptr = TRUE;
			if (DrawCheck(player_check, t4) == true)
				*isTrapped_ptr = TRUE;
			if (DrawCheck(player_check, k) == true)
				*isColide_ptr = TRUE;
			if (DrawCheck(player_check, t5) == true)
				*isTrapped_ptr = TRUE;
			if (DrawCheck(player_check, l) == true)
				*isColide_ptr = TRUE;


			if (DrawCheck(player_check, m) == true)
				*isColide_ptr = TRUE;
			if (DrawCheck(player_check, n) == true)
				*isColide_ptr = TRUE;
			if (DrawCheck(player_check, o) == true)
				*isColide_ptr = TRUE;
			if (DrawCheck(player_check, t6) == true)
				*isTrapped_ptr = TRUE;;
			if (DrawCheck(player_check, p) == true)
				*isColide_ptr = TRUE;

			if (DrawCheck(player_check, q) == true)
				*isColide_ptr = TRUE;
			if (DrawCheck(player_check, t7) == true)
				*isTrapped_ptr = TRUE;
			if (DrawCheck(player_check, r) == true)
				*isColide_ptr = TRUE;

			if (DrawCheck(player_check, s) == true)
				*isColide_ptr = TRUE;

			if (DrawCheck(player_check, t) == true)
				*isColide_ptr = TRUE;
			if (DrawCheck(player_check, t8) == true)
				*isTrapped_ptr = TRUE;
			if (DrawCheck(player_check, u) == true)
				*isColide_ptr = TRUE;

			if (DrawCheck(player_check, v) == true)
				*isColide_ptr = TRUE;
		}

		/*�� ���� �浹 ���� �߰� ������*/
		{addDrawCheck(&w1, 87, 27, 29);
		addDrawCheck(&w3, 51, 27, 29);
		addDrawCheck(&w4, 43, 24,26);
		addDrawCheck(&w5, 35, 21, 23);
		addDrawCheck(&w6, 27, 20, 12);
		addDrawCheck(&w10, 111, 9, 9);
		addDrawCheck(&w12, 11, 14, 15);
		addDrawCheck(&w14, 13, 25, 26);
		}

		/*�� ���� �浹 �Լ� ���� ������*/
		{
			if (DrawCheck(player_check, w1) == true)
				*isWallHitR_ptr = TRUE;
			if (DrawCheck(player_check, w3) == true)
				*isWallHitR_ptr = TRUE;
			if (DrawCheck(player_check, w4) == true)
				*isWallHitR_ptr = TRUE;
			if (DrawCheck(player_check, w5) == true)
				*isWallHitR_ptr = TRUE;
			if (DrawCheck(player_check, w6) == true)
				*isWallHitR_ptr = TRUE;
			if (DrawCheck(player_check, w10) == true)
				*isWallHitR_ptr = TRUE;
			if (DrawCheck(player_check, w12) == true)
				*isWallHitR_ptr = TRUE;
			if (DrawCheck(player_check, w14) == true)
				*isWallHitR_ptr = TRUE;
		}
		
		/*�� ���� �浹 ���� �߰� ����*/
		{addDrawCheck(&w2, 79, 27, 29);
		addDrawCheck(&w7, 43, 19, 20);
		addDrawCheck(&w8, 49, 17, 18);
		addDrawCheck(&w9, 115, 13, 13);
		addDrawCheck(&w11, 11, 8, 8);
		addDrawCheck(&w13, 7, 19, 19);
		addDrawCheck(&w15, 19, 18, 9);
		addDrawCheck(&w16, 7, 20,29 );
		}

		/*�� ���� �浹 �Լ� ���� ������*/
		{
			if (DrawCheck(player_check, w2) == true)
				*isWallHitL_ptr = TRUE;
			if (DrawCheck(player_check, w7) == true)
				*isWallHitL_ptr = TRUE;
			if (DrawCheck(player_check, w8) == true)
				*isWallHitL_ptr = TRUE;
			if (DrawCheck(player_check, w9) == true)
				*isWallHitL_ptr = TRUE;
			if (DrawCheck(player_check, w11) == true)
				*isWallHitL_ptr = TRUE;
			if (DrawCheck(player_check, w13) == true)
				*isWallHitL_ptr = TRUE;
			if (DrawCheck(player_check, w15) == true)
				*isWallHitL_ptr = TRUE;
			if (DrawCheck(player_check, w16) == true)
				*isWallHitL_ptr = TRUE;
		}


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


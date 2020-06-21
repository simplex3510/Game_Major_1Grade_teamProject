// #Pragma 지시문은 컴퓨터 또는 운영 체제별 컴파일러 기능을 지정
#pragma once					// 헤더의 중복을 방지함
#pragma warning (disable:4996)	// 보안 위험 무시

#include <stdio.h>				// 표준 입출력 헤더
#include <conio.h>				// 콘솔 입출력 함수 헤더, 표준에서 벗어남

#include "screen.h"				// 윈도우 화면 출력 처리 헤더
#include "maps.h"				// 맵 데이터 헤더
#include "object.h"				// 오브젝트 데이터 헤더
#include "SoundManager.h"		// 사운드 데이터 헤더
#include "GroundCheck.h"		// 충돌 관련 헤더

#define TRUE		1
#define ESC			27

#define SOUND_UP	91
#define SOUND_DOWN	93

#define ARROW		224
#define UP			72
#define DOWN		80
#define LEFT		75
#define RIGHT		77

double volume = 0;

int LOOP = TRUE;
int isColide = FALSE;					// 플레이어 충돌체크
int* isColide_ptr = &isColide;

int isTrapped = FALSE;					// 가시 충돌 체크
int* isTrapped_ptr = &isTrapped;

int isWallHitR = FALSE;					// 왼쪽 벽 충돌 체크
int* isWallHitR_ptr = &isWallHitR;

int isWallHitL = FALSE;					// 왼쪽 벽 충돌체크
int* isWallHitL_ptr = &isWallHitL;

clock_t curTime;
clock_t oldTime;

Player player;		// 플레이어 오브젝트 선언
Object potal;		// 포탈 오브젝트 선언
Object home;		// 홈 오브젝트 선언

MMX player_check;	// 플레이어 충돌체
MMX platform;		// 플렛폼 충돌체
MMX fence;			// 메인 프레임 출돌체

MMX platform_stage2_2;

typedef struct {
	float x;
	float y;
}saveP;

saveP curPP;
saveP prevPP;

static int stage = 1;


void init()
{
	player_init(&player);		// 플레이어 초기화
	potal_init(&potal, stage);	// 포탈 초기화
	home_init(&home);

	sound_init();				// FMOD 초기화

	// 맵 프레임 충돌체
	fence.max.x = 122;	fence.max.y = 29;
	fence.min.x = 2;	fence.min.y = 29;
	DrawCheck(player_check, fence);

	curPP.x = player.position.x;
	curPP.y = player.position.y;

	prevPP.x = player.position.x;
	prevPP.y = player.position.y;
}

void addDrawCheck(MMX* a, float mx, float my, float Mx)
{
	a->max.x = Mx;
	a->max.y = my + 1;
	a->min.x = mx;
	a->min.y = my;
}

void addDrawCheckW(MMX* a, float mx, float my, float My)
{
	a->max.x = mx;
	a->max.y = My;
	a->min.x = mx;
	a->min.y = my;
}

void addDrawCheckO(MMX* a, float mx, float my, float Mx, float My)
{
	a->max.x = Mx;
	a->max.y = My;
	a->min.x = mx;
	a->min.y = my;
}

void update()
{
	clock_t curTime = clock();

	prevPP.x = curPP.x;
	prevPP.y = curPP.y;

	curPP.x = player.position.x;
	curPP.y = player.position.y;


	//while (player.bounce.jumpTime_middle < (curTime - player.bounce.oldTime)) {
	//
	//	// 최고점이 아니라면, 상승한다.
	//	if ((TRUE <= *isColide_ptr) && (*isColide_ptr <= 6)) {
	//		player.position.y -= 0.5;
	//		(*isColide_ptr)++;
	//		// 최고점에 다랐을 경우, 
	//		if (*isColide_ptr == 6) {
	//			*isColide_ptr = FALSE;
	//		}
	//		player.bounce.oldTime = curTime;	// 점프 시점 시각 업데이트
	//
	//		return;
	//	}
	//	// 최고점이라면, 하강한다.
	//	else if (*isColide_ptr == FALSE) {
	//		player.position.y += 0.5;
	//		// 다시 내려왔을 경우
	//		player.bounce.oldTime = curTime;	// 점프 시점 시각 업데이트
	//		return;
	//	}
	//}

	if ((1 <= *isColide_ptr) && (*isColide_ptr <= 2)) {
		while (player.bounce.jumpTime_low < (curTime - player.bounce.oldTime)) {
			// 최고점이 아니라면, 상승한다.
			player.position.y -= 0.5;
			(*isColide_ptr)++;
			player.bounce.oldTime = curTime;	// 점프 시점 시각 업데이트
			if ( *isColide_ptr == 2)
				playEffectSound(1);
			return;
		}
	}
	else if ((3 <= *isColide_ptr) && (*isColide_ptr <= 4)) {
		while (player.bounce.jumpTime_middle < (curTime - player.bounce.oldTime)) {

			// 최고점이 아니라면, 상승한다.
			player.position.y -= 0.5;
			(*isColide_ptr)++;
			player.bounce.oldTime = curTime;	// 점프 시점 시각 업데이트

			return;
		}
	}
	else if (*isColide_ptr == 5) {
		while (player.bounce.jumpTime_high < (curTime - player.bounce.oldTime)) {

			// 최고점이 아니라면, 상승한다.
			player.position.y -= 0.5;
			(*isColide_ptr)++;
			// 최고점에 다랐을 경우, 
			if (*isColide_ptr == 6) {
				*isColide_ptr = -1;
			}
			player.bounce.oldTime = curTime;	// 점프 시점 시각 업데이트

			return;
		}
	}


	if ((-2 <= *isColide_ptr) && (*isColide_ptr <= -1)) {
		while (player.bounce.jumpTime_high < (curTime - player.bounce.oldTime)) {

			// 최고점이라면, 하강한다.
			player.position.y += 0.5;
			(*isColide_ptr)--;
			// 다시 내려왔을 경우
			player.bounce.oldTime = curTime;	// 점프 시점 시각 업데이트
			return;
		}
	}
	else if ((-4 <= *isColide_ptr) && (*isColide_ptr <= -3)) {
		while (player.bounce.jumpTime_middle < (curTime - player.bounce.oldTime)) {

			// 최고점이라면, 하강한다.
			player.position.y += 0.5;
			(*isColide_ptr)--;
			// 다시 내려왔을 경우
			player.bounce.oldTime = curTime;	// 점프 시점 시각 업데이트
			return;
		}
	}
	else if (*isColide_ptr < 0) {
		while (player.bounce.jumpTime_low < (curTime - player.bounce.oldTime)) {

			// 최고점이라면, 하강한다.
			player.position.y += 0.5;
			(*isColide_ptr)--;
			// 다시 내려왔을 경우
			player.bounce.oldTime = curTime;	// 점프 시점 시각 업데이트
			return;
		}
	}

	/*if (*isWallHitL_ptr == true)
	{
		player.position.x -= 2;
	}

	if (*isWallHitR_ptr == true)
	{
		player.position.x += 2;
	}*/
}

// 화면에 출력
void render()
{
	// 화면을 다시 그리기 위해 비우기
	screenClear();

	char string[100] = { 0, };
	char str_stage[50] = { 0, };
	char str_colide[20] = { 0, };

	player_check.min.x = player.position.x;
	player_check.min.y = player.position.y;
	player_check.max.x = player.position.x + 1;
	player_check.max.y = player.position.y;

	// 트랩과 충돌하면
	if (*isTrapped_ptr == true) {

		stage = 1;

		potal.position.x = 120;
		potal.position.y = 28;

		home.position.x = 122;
		home.position.y = 0;

		*isTrapped_ptr = FALSE;
	}

	// 포탈 충돌 체크, 다음 스테이지
	if ((player.position.x == potal.position.x) &&
		(player.position.y == potal.position.y)) {

		playEffectSound(2);

		stage++;
		object_position(&player, &potal, &home, stage);

	}
	// 홈 충돌 체크, 다음 스테이지
	else if ((player.position.x == home.position.x) &&
		(player.position.y == home.position.y)) {

		playEffectSound(2);

		stage++;
		object_position(&player, &potal, &home, stage);
	}

	// 스테이지 출력
	switch (stage)
	{
	case 1:
		stage1();

		if (DrawCheck(player_check, fence) == true)
			*isColide_ptr = TRUE;

		break;
	case 2:
		stage2();

		MMX platform, platform1, wcs, cl, f, sos, Iic, bscegh, dywgtc;

		DrawCheck(player_check, platform_stage2_2);
		if (DrawCheck(player_check, platform_stage2_2) == true)
			*isColide_ptr = TRUE;



		DrawCheck(player_check, fence);
		if (DrawCheck(player_check, fence) == true)
			*isColide_ptr = TRUE;

		addDrawCheck(&wcs, 26.5, 23, 32.5);
		addDrawCheck(&platform, 2, 26, 110);
		addDrawCheckO(&platform1, 110, 27, 110, 29);
		addDrawCheck(&cl, 9.5, 20, 25.5);
		addDrawCheck(&f, 30.5, 17, 44.5);
		addDrawCheck(&sos, 50.5, 14, 64.5);
		addDrawCheck(&Iic, 70.5, 11, 84.5);
		addDrawCheck(&bscegh, 89.5, 8.5, 105.5);
		addDrawCheck(&dywgtc, 99.5, 5.5, 122);

		if (DrawCheck(player_check, platform) == true)
			*isColide_ptr = TRUE;

		if (DrawCheck(player_check, platform1) == true)
		{
			screenPrint(player.position.x += 2, player.position.y, player.strobject);
		}

		if (DrawCheck(player_check, wcs) == true)
			*isColide_ptr = TRUE;

		if (DrawCheck(player_check, cl) == true)
			*isColide_ptr = TRUE;

		if (DrawCheck(player_check, f) == true)
			*isColide_ptr = TRUE;
		if (DrawCheck(player_check, sos) == true)
			*isColide_ptr = TRUE;

		if (DrawCheck(player_check, Iic) == true)
			*isColide_ptr = TRUE;

		if (DrawCheck(player_check, bscegh) == true)
			*isColide_ptr = TRUE;
		if (DrawCheck(player_check, dywgtc) == true)
			*isColide_ptr = TRUE;

		break;

	case 3:
		// 스테이지3 불러오기
		stage3(&platform);

		//MMX map[21] = { 0, };
		//MMX a, b, c, d, e, F, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v;
		//map[0] = a;			map[1] = b;			map[2] = c;			map[3] = d;
		//map[4] = e;			map[5] = f;			map[6] = g;			map[7] = h;
		//map[8] = i;			map[9] = j;			map[10] = k;		map[11] = l;
		//map[12] = m;		map[12] = n;		map[13] = o;		map[14] = p;
		//map[15] = q;		map[16] = r;		map[17] = s;		map[18] = t;
		//map[19] = u;		map[20] = v;

		//MMX trap[9] = { 0, };
		//MMX t1, t2, t3, t4, t5, t6, t7, t8;
		//trap[0] = t1;		trap[1] = t2;		trap[3] = t3;		trap[4] = t4;
		//trap[5] = t5;		trap[6] = t6;		trap[7] = t7;		trap[8] = t8;

		//MMX w1, w2, w3, w4, w5, w6, w7, w8, w9, w10, w11, w12, w13, w14, w15, w16;

		MMX* map[32] = { 0, };
		MMX a, b, c, d, e, F, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y1, y2, z1, z2, e1, f1, g1, c1, c2;
		map[0] = &a;		map[1] = &b;		map[2] = &c;		map[3] = &d;
		map[4] = &e;		map[5] = &f;		map[6] = &g;		map[7] = &h;
		map[8] = &i;		map[9] = &j;		map[10] = &k;		map[11] = &l;
		map[12] = &m;		map[12] = &n;		map[13] = &o;		map[14] = &p;
		map[15] = &q;		map[16] = &r;		map[17] = &s;		map[18] = &t;
		map[19] = &u;		map[20] = &v;		map[21] = &w;		map[22] = &x;
		map[23] = &y1;		map[24] = &y2;		map[25] = &z1;		map[26] = &z2;
		map[27] = &e1;		map[28] = &f1;		map[29] = &g1;		map[30] = &c1;		map[31] = &c2;

		MMX* trap[9] = { 0, };
		MMX t1, t2, t3, t4, t5, t6, t7, t8;
		trap[0] = &t1;		trap[1] = &t2;		trap[3] = &t3;		trap[4] = &t4;
		trap[5] = &t5;		trap[6] = &t6;		trap[7] = &t7;		trap[8] = &t8;


		DrawCheck(player_check, platform);
		if (DrawCheck(player_check, platform) == true)
			*isColide_ptr = TRUE;

		DrawCheck(player_check, fence);
		if (DrawCheck(player_check, fence) == true)
			*isColide_ptr = TRUE;

		/*맵 이동 및 트랩 충돌 변수 초기화*/
		{addDrawCheck(&a, 104, 29, 122);

		addDrawCheck(&t1, 100, 29, 102);

		addDrawCheck(&b, 88, 29, 98);
		addDrawCheck(&c, 80, 26, 86);

		addDrawCheck(&t2, 78, 29, 78);

		addDrawCheck(&d, 52, 29, 76);
		addDrawCheck(&e, 44, 26, 50);
		addDrawCheck(&F, 36, 23, 42);
		addDrawCheck(&g, 28, 20, 34);
		addDrawCheck(&h, 44, 18, 48);
		addDrawCheck(&i, 50, 16, 64);

		addDrawCheck(&t3, 66, 16, 68);
		addDrawCheck(&j, 70, 16, 78);
		addDrawCheck(&t4, 80, 16, 82);
		addDrawCheck(&k, 84, 16, 92);
		addDrawCheck(&t5, 94, 16, 96);
		addDrawCheck(&l, 98, 16, 122);


		addDrawCheck(&m, 116, 12, 122);
		addDrawCheck(&n, 104, 8, 104);
		addDrawCheck(&w, 106, 9, 106);
		addDrawCheck(&x, 108, 10, 108);

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

		addDrawCheckO(&y1, 20, 9, 20, 20);
		addDrawCheckO(&y2, 26, 9, 26, 20);
		addDrawCheckO(&z1, 20, 21, 20, 29);
		addDrawCheckO(&z2, 26, 21, 26, 29);

		addDrawCheckO(&e1, 50, 27, 50, 29);
		addDrawCheckO(&f1, 42, 24, 42, 26);
		addDrawCheckO(&g1, 34, 21, 34, 23);

		addDrawCheckO(&c1, 80, 27, 80, 29);
		addDrawCheckO(&c2, 86, 27, 86, 29);
		}

		/*맵 이동 및 트랩 충돌 함수 실행*/
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
			if (DrawCheck(player_check, F) == true)
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
			if (DrawCheck(player_check, w) == true)
				*isColide_ptr = TRUE;
			if (DrawCheck(player_check, x) == true)
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

		// 충돌체
		{
		if ((c.min.x < player.position.x) && (c.max.x > player.position.x)
			&& (c.min.y < player.position.y) && (c.max.y > player.position.y))
		{
			screenPrint(prevPP.x, prevPP.y, player.strobject);
		}
		if ((e.min.x < player.position.x) && (e.max.x > player.position.x)
			&& (e.min.y < player.position.y) && (e.max.y > player.position.y))
		{
			screenPrint(prevPP.x, prevPP.y, player.strobject);
		}
		if ((F.min.x < player.position.x) && (F.max.x > player.position.x)
			&& (F.min.y < player.position.y) && (F.max.y > player.position.y))
		{
			screenPrint(prevPP.x, prevPP.y, player.strobject);
		}
		if ((g.min.x < player.position.x) && (g.max.x > player.position.x)
			&& (g.min.y < player.position.y) && (g.max.y > player.position.y))
		{
			screenPrint(prevPP.x, prevPP.y, player.strobject);
		}
		if ((h.min.x < player.position.x) && (h.max.x > player.position.x)
			&& (h.min.y < player.position.y) && (h.max.y > player.position.y))
		{
			screenPrint(prevPP.x, prevPP.y, player.strobject);
		}
		if ((i.min.x < player.position.x) && (i.max.x > player.position.x)
			&& (i.min.y < player.position.y) && (i.max.y > player.position.y))
		{
			screenPrint(prevPP.x, prevPP.y, player.strobject);
		}
		if ((m.min.x < player.position.x) && (m.max.x > player.position.x)
			&& (m.min.y < player.position.y) && (m.max.y > player.position.y))
		{
			screenPrint(prevPP.x, prevPP.y, player.strobject);
		}
		if ((n.min.x < player.position.x) && (n.max.x > player.position.x)
			&& (n.min.y < player.position.y) && (n.max.y > player.position.y))
		{
			screenPrint(prevPP.x, prevPP.y, player.strobject);
		}
		if ((o.min.x < player.position.x) && (o.max.x > player.position.x)
			&& (o.min.y < player.position.y) && (o.max.y > player.position.y))
		{
			screenPrint(prevPP.x, prevPP.y, player.strobject);
		}
		if ((p.min.x < player.position.x) && (p.max.x > player.position.x)
			&& (p.min.y < player.position.y) && (p.max.y > player.position.y))
		{
			screenPrint(prevPP.x, prevPP.y, player.strobject);
		}
		if ((q.min.x < player.position.x) && (q.max.x > player.position.x)
			&& (q.min.y < player.position.y) && (q.max.y > player.position.y))
		{
			screenPrint(prevPP.x, prevPP.y, player.strobject);
		}
		if ((s.min.x < player.position.x) && (s.max.x > player.position.x)
			&& (s.min.y < player.position.y) && (s.max.y > player.position.y))
		{
			screenPrint(prevPP.x, prevPP.y, player.strobject);
		}
		if ((u.min.x < player.position.x) && (u.max.x > player.position.x)
			&& (u.min.y < player.position.y) && (u.max.y > player.position.y))
		{
			screenPrint(prevPP.x, prevPP.y, player.strobject);
		}
		if ((w.min.x < player.position.x) && (w.max.x > player.position.x)
			&& (w.min.y < player.position.y) && (w.max.y > player.position.y))
		{
			screenPrint(prevPP.x, prevPP.y, player.strobject);
		}
		if ((x.min.x < player.position.x) && (x.max.x > player.position.x)
			&& (x.min.y < player.position.y) && (x.max.y > player.position.y))
		{
			screenPrint(prevPP.x, prevPP.y, player.strobject);
		}
		if (DrawCheck(player_check, y1) == true)
		{
			player.position.x -= 2;
		}
		if (DrawCheck(player_check, y2) == true)
		{
			player.position.x += 2;
		}
		if (DrawCheck(player_check, z1) == true)
		{
			player.position.x -= 2;
		}
		if (DrawCheck(player_check, z2) == true)
		{
			player.position.x += 2;
		}
		if (DrawCheck(player_check, e1) == true)
		{
			screenPrint(player.position.x += 2, player.position.y, player.strobject);
		}
		if (DrawCheck(player_check, f1) == true)
		{
			screenPrint(player.position.x += 2, player.position.y, player.strobject);
		}
		if (DrawCheck(player_check, g1) == true)
		{
			screenPrint(player.position.x += 2, player.position.y, player.strobject);
		}
		if (DrawCheck(player_check, c1) == true)
		{
			screenPrint(player.position.x -= 2, player.position.y, player.strobject);
		}
		if (DrawCheck(player_check, c2) == true)
		{
			screenPrint(player.position.x += 2, player.position.y, player.strobject);
		}
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

	// 왼쪽으로 벗어나는 경우
	if (player.position.x < 2) {
		screenPrint(2, player.position.y, player.strobject);
		player.position.x = 2.0;
	}
	// 오른쪽으로 벗어나는 경우
	else if (122 < player.position.x) {
		screenPrint(122, player.position.y, player.strobject);
		player.position.x = 122.0;
	}
	// 아래쪽으로 벗어나는 경우
	else if (29 < player.position.y) {
		screenPrint(player.position.x, 29.0, player.strobject);
		player.position.y = 29.0;
	}
	// 윗쪽으로 벗어나는 경우
	else if (player.position.y < 2) {
		screenPrint(player.position.x, 2.0, player.strobject);
		player.position.y = 2.0;
	}
	// 일반 렌더링
	else {
		screenPrint(home.position.x, home.position.y, home.strobject);			// 홈 렌더링
		screenPrint(potal.position.x, potal.position.y, potal.strobject);		// 포탈 렌더링
		screenPrint(player.position.x, player.position.y, player.strobject);	// 플레이어 렌더링
	}


	sprintf(str_colide, "충돌: %d", isColide);
	screenPrint(70, 0, str_colide);
	sprintf(str_stage, "스테이지: %d", stage);
	screenPrint(50, 0, str_stage);
	sprintf(string, "캐릭터 이동 좌표: (%f, %f)", player.position.x, player.position.y);
	screenPrint(0, 0, string);

	// 스크린 버퍼 전환
	screenFlipping();
}

// 동적 할당 해제
void release()
{

}

// 프레임 조정
void waitRender(clock_t oldTime)
{
	while (TRUE) {

		curTime = clock();			// 렌더 후의 시간을 지속적으로 갱신
		if (10 < curTime - oldTime)			// 두 시간의 차가 (16ms - 60 fps) or (33ms - 30fps)일 때 대기상태 탈출, 10으로하니까 60프레임
			break;
	}
}

// 키 인식
int getKeyEvent()
{
	int key1, key2;

	if (_kbhit()) {						// 키보드 입력 인식
		key1 = _getch();				// 방향키 첫 번째 아스키 코드 값 저장

		if (key1 == ESC)					// esc키 입력
			return key1;				// 해당 키보드 값 반환

		if (key1 == SOUND_UP);
			return key1;

		if (key1 == SOUND_DOWN);
			return key1;

		// --------------방향키 존---------------
		key2 = _getch();				// 방향키 두 번째 아스키 코드 값 저장
		if (key1 == ARROW)				// 방향키가 입력되었을 때
			return key2;				// 방향키 입력값 반환
	}

	return -1;						// 방향키 입력이 아니면 -1 반환
}

// 인식된 키에 대응하는 명령 실행
void keyProcess(int key)
{

	switch (key) {					// 값에 따라 방향키 케이스 분할
	case UP:
		//printf("↑");
		player.position.y -= 1;
		break;
	case DOWN:
		//printf("↓");
		player.position.y += 1;
		break;
	case LEFT:
		//printf("←");
		player.position.x -= 2;
		break;
	case RIGHT:
		//printf("→");
		player.position.x += 2;
		break;

	case SOUND_UP:
		volume += 0.1f;
		if (volume > 1.0f)
			volume = 1.0f;
		sound_bgmVolume(volume);
		sound_effectVolume(volume);
		break;

	case SOUND_DOWN:
		volume -= 0.1f;
		if (volume < 0.0f)
			volume = 0.0f;
		sound_bgmVolume(volume);
		sound_effectVolume(volume);
		break;
	
	}
}

int main()
{
	screenInit();	// 스크린 초기화
	init();			// 게임 초기화
	playBgmSound(1);			// 1번째 브금 실행
	sound_bgmVolume(0.1f);		// 배경음 볼륨 0,1로 조절

	int nKey;

	// 메인 루프
	while (LOOP) {

		nKey = getKeyEvent();
		if (nKey == ESC) {		// ESC 입력
			break;				// 반복 탈출 후, 게임 종료
		}

		keyProcess(nKey);		// 키 프로세스 진행

		update();				// 데이터 업데이트

		sound_update();			// FMOD 업데이트

		render();				// 그래픽 렌더링
		waitRender(oldTime);
	}

	release();					// 동적할당 헤제
	screenRelease();			// 스크린 해제
	sound_release();			// FMOD 종료

	printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t    Thank you for your playing!\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	Sleep(1500);

	return 0;
}
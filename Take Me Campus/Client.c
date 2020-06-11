#pragma once
#pragma warning (disable:4996)

#include <stdio.h>			// 표준 입출력 헤더
#include <conio.h>			// 입출력, 표준에서 벗어남

#include "screen.h"			// 렌더링 처리 헤더
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

Player player;		// 플레이어 오브젝트 선언
Object potal;		// 포탈 오브젝트 선언
Object home;
Object side[3];

MMX player_check;
MMX platform;
MMX fence;

MMX platform_stage2_2;

static int stage = 1;



void init()
{
	player_init(&player);		// 플레이어 초기화
	potal_init(&potal, stage);	// 포탈 초기화
	home_init(&home);

	sound_init();				// FMOD 초기화
	
	for (int i = 0; i < 3; i++)
		side_init(&side[i], i);

	// 맵 프레임 충돌체
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

void update()
{
	clock_t curTime = clock();
	static int count = 0;

	// 즉, 최근 시간과 이전 시간을 빼면 시간차가 나오는데, 이게 일정 수준보다 커야함
	// -> 점프와 점프 사이의 시간적 간격 = 점프 속도
	// 점프와 점프사이의 시간차 < (최근시간 - 이전 시간)

	//while (player.bounce.jumpTime < (curTime - player.bounce.oldTime)) {
	//
	//	// 최고점이 아니라면, 상승한다.
	//	if ((player.bounce.isTop == 0) || (*isColide_ptr == TRUE)) {
	//		player.position.y--;
	//		count++;
	//		// 최고점에 다랐을 경우, 
	//		if (count == 3) { player.bounce.isTop = 1; }
	//		player.bounce.oldTime = curTime;	// 점프 시점 시각 업데이트
	//
	//		return;
	//	}
	//	// 최고점이라면, 하강한다.
	//	else if ((player.bounce.isTop == 1) || (*isColide_ptr == FALSE)) {
	//		player.position.y++;
	//		count++;
	//		// 다시 내려왔을 경우
	//		if (count == 6) { player.bounce.isTop = 0; count = 0; }
	//		player.bounce.oldTime = curTime;	// 점프 시점 시각 업데이트
	//		return;
	//	}
	//}

	while (player.bounce.jumpTime < (curTime - player.bounce.oldTime)) {

		// 최고점이 아니라면, 상승한다.
		if ( (TRUE <= *isColide_ptr) && (*isColide_ptr <= 4) ) {
			player.position.y--;
			(*isColide_ptr)++;
			// 최고점에 다랐을 경우, 
			if (*isColide_ptr == 4) {
				*isColide_ptr = FALSE;
			}
			player.bounce.oldTime = curTime;	// 점프 시점 시각 업데이트

			return;
		}
		// 최고점이라면, 하강한다.
		else if ( (*isColide_ptr == FALSE) ) {
			player.position.y++;
			// 다시 내려왔을 경우
			//if (*isColide_ptr == TRUE) { player.bounce.isTop = 0; count = 0; }
			player.bounce.oldTime = curTime;	// 점프 시점 시각 업데이트
			return;
		}
	}
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

	// 포탈 충돌 체크, 다음 스테이지
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

		MMX wcs, cl, f, sos, Iic, bscegh, dywgtc;
		

		// 절벽 옆부분 막아놓음
		stage2_Colide_side(&player, &side[0]);
		stage2_Colide_side(&player, &side[1]);
		stage2_Colide_side(&player, &side[2]);

		// 절벽 위 충돌체
		stage2_Colide0(&platform);

		// 첫 번째 플랫폼 충돌체
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
		// 스테이지3 불러오기
		stage3(&platform);

		MMX a, b, c, d, e, F, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v;
		MMX t1, t2, t3, t4, t5, t6, t7, t8;


		DrawCheck(player_check, platform);
		if (DrawCheck(player_check, platform) == true)
			*isColide_ptr = TRUE;

		DrawCheck(player_check, fence);
		if (DrawCheck(player_check, fence) == true)
			*isColide_ptr = TRUE;

		{addDrawCheck(&a, 104, 29, 122);

		addDrawCheck(&t1, 100, 29, 102);

		addDrawCheck(&b, 88, 29, 98);
		addDrawCheck(&c, 80, 26, 86);

		addDrawCheck(&t2, 74, 29, 78);

		addDrawCheck(&d, 52, 29, 72);
		addDrawCheck(&e, 44, 26, 50);
		addDrawCheck(&F, 36, 23, 42);
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
		
		addDrawCheck(&u, 12, 24, 12);
		addDrawCheck(&v, 2, 29, 18);
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

	// 왼쪽으로 벗어나는 경우 - 클리핑 기술 활용
	if (player.position.x < 2) {
		screenPrint(2, player.position.y, player.strobject);
		player.position.x = 2;
	}
	// 오른쪽으로 벗어나는 경우
	else if (122 < player.position.x) {
		screenPrint(122, player.position.y, player.strobject);
		player.position.x = 122;
	}
	// 아래쪽으로 벗어나는 경우
	else if (29 < player.position.y) {
		screenPrint(player.position.x, 29, player.strobject);
		player.position.y = 29;
	}
	// 윗쪽으로 벗어나는 경우
	else if (player.position.y < 2) {
		screenPrint(player.position.x, 2, player.strobject);
		player.position.y = 2;
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

	printf("Thank you for your playing!");

	return 0;
}


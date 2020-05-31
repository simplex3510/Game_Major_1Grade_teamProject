#include <stdio.h>			// 표준 입출력 헤더
#include <conio.h>			// 입출력, 표준에서 벗어남

#include "fps.h"			// fps 출력 헤더
#include "screen.h"			// 렌더링 처리 헤더
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


FPSData* fpsData;	// fpsData를 FPSData 포인터 형식으로 선언 

Player player;		// 플레이어 오브젝트 선언
Object potal;		// 포탈 오브젝트 선언
Object platform[5];

static int stage = 1;


void init()
{
	initFPSData(&fpsData);		// FPS 초기화
	player_init(&player);		// 플레이어 초기화
	potal_init(&potal, stage);	// 포탈 초기화
	for (int i = 0; i < 3; i++)
	{
		platform_init(&platform[i], i);
	}

}

// 점프 데이터 업데이트
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

// 화면에 출력
void render()
{
	screenClear();
	drawFPS(&fpsData);

	char string[100] = { 0, };

	// 포탈 충돌 체크, 다음 스테이지
	if ((player.position.x == potal.position.x) &&
		(player.position.y == potal.position.y)) {
		stage++;
		object_position(&potal, &player, stage);
	}

	sprintf(string, "캐릭터 이동 좌표: (%d, %d)", player.position.x, player.position.y);

	// 스테이지 출력

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

	wallColide(&player);												// 외곽 벽 충돌체크

	screenPrint(potal.position.x, potal.position.y, potal.strobject);		// 포탈 렌더링

	screenPrint(player.position.x, player.position.y, player.strobject);	// 플레이어 렌더링

	screenPrint(10, 0, string);
	screenFlipping();
}

// 동적 할당 해제
void release()
{
	// FPS 관련 동적할당 2개 해제
	freeFPSData(&fpsData);

}

// 프레임 조정
void waitRender(clock_t oldTime)
{
	clock_t curTime;
	while (TRUE) {

		curTime = clock();					// 렌더 후의 시간을 지속적으로 갱신
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

		key2 = _getch();				// 방향키 두 번째 아스키 코드 값 저장
		if (key1 == ARROW)				// 방향키가 입력되었을 때
			return key1, key2;			// 방향키 입력값 반환
	}

	return -1;						// 방향키 입력이 아니면 -1 반환
}

// 인식된 키에 대응하는 명령 실행
void keyProcess(int key2)
{

	switch (key2) {					// 값에 따라 방향키 케이스 분할
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

	int nKey;

	// 메인 루프
	while (TRUE) {

		nKey = getKeyEvent();
		if (nKey == 27)		// ESC 입력
			break;				// 반복 탈출 후, 게임 종료

		keyProcess(nKey);		// 키 프로세스 진행

		update();				// 데이터 업데이트

		render();				// 그래픽 렌더링

		waitRender(clock());	// 프레임 수 조절
	}

	release();					// 동적할당 헤제
	screenRelease();			// 스크린 동적 할당 해제

	printf("Thank you for your playing!");

	return 0;
}
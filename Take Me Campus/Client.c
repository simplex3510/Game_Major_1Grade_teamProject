#include <stdio.h>			// 표준 입출력 헤더
#include <time.h>			// 시간과 관련된 함수 헤더
#include <conio.h>			// 입출력, 표준에서 벗어남
#include <string.h>

#include "fps.h"			// fps 출력 헤더
#include "screen.h"			// 렌더링 처리 헤더
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
	player_init(&player);		// 플레이어 초기화
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

	// 스테이지 클리어
	if ((player.position.x == potal.position.x) &&
		(player.position.y == potal.position.y)) {
		stage++;
		potal_init(&potal, stage);
	}

	sprintf(string, "캐릭터 이동 좌표: (%d, %d)", player.position.x, player.position.y);
	
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

	// 왼쪽으로 벗어나는 경우 - 클리핑 기술 활용
	if (player.position.x < 2) {
		screenPrint(2, player.position.y, player.strPlayer);
		player.position.x = 2;
	}
	// 오른쪽으로 벗어나는 경우
	else if (122 < player.position.x) {
		screenPrint(122, player.position.y, player.strPlayer);
		player.position.x = 122;
	}
	// 아래쪽으로 벗어나는 경우
	else if (29 < player.position.y) {
		screenPrint(player.position.x, 29, player.strPlayer);
		player.position.y = 29;
	}
	// 윗쪽으로 벗어나는 경우
	else if (player.position.y < 2) {
		screenPrint(player.position.x, 2, player.strPlayer);
		player.position.y = 2;
	}
	// 일반 렌더링
	else {
		screenPrint(potal.position.x, potal.position.y, potal.strPlayer);
		screenPrint(player.position.x, player.position.y, player.strPlayer);
	}
	
	screenPrint(10, 0, string);
	screenFlipping();
}

// 동적 할당 해제
void release()
{
	destoyFPSData(&fpsData);



	// 캐릭터, 포탈, 
	
}

void waitRender(clock_t oldTime)
{
	clock_t curTime;
	while (TRUE) {

		curTime = clock();					// 렌더 후의 시간을 지속적으로 갱신
		if (16 < curTime - oldTime)			// 두 시간의 차가 (16ms - 60 fps) or (33ms - 30fps)일 때 대기상태 탈출
			break;
	}
}

int getKeyEvent()
{
	int key1, key2;
	if (_kbhit()) {					// 키보드 입력 인식
		key1 = _getch();			// 방향키 첫 번째 아스키 코드 값 저장

		if (key1 == 27)			// esc키 입력
			return key1;		// 해당 키보드 값 반환

		key2 = _getch();		// 방향키 두 번째 아스키 코드 값 저장
		if (key1 == 224)			// 방향키가 입력되었을 때
			return key1, key2;			// 방향키 입력값 반환
		
			
	}

	return -1;						// 방향키 입력이 아니면 -1 반환
}

void keyProcess(int key2)
{

	switch (key2) {					// 값에 따라 방향키 케이스 분할
	case 80:
		printf("↑");
		player.position.y += 1;
		break;
	case 72:
		printf("↓");
		player.position.y -= 1;
		break;
	case 75:
		//printf("←");
		player.position.x -= 2;
		break;
	case 77:
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

	while (TRUE) {
		
		nKey = getKeyEvent();
		if (nKey == 27)		// ESC 입력
			break;				// 반복 탈출 후, 게임 종료

		keyProcess(nKey);		// 키 프로세스 진행

		update();				// 데이터 업데이트

		render();				// 그래픽 렌더링
		waitRender(clock());
	}

	release();					// 동적할당 헤제
	screenRelease();			// 스크린 동적 할당 해제

	return 0;
}
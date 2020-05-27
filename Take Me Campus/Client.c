#include <stdio.h>			// 표준 입출력 헤더
#include <time.h>			// 시간과 관련된 함수 헤더
#include <conio.h>			// 입출력, 표준에서 벗어남
#include <string.h>

#include "fps.h"			// fps 출력 헤더
#include "screen.h"			// 렌더링 처리 헤더
#include "maps.h"

#pragma warning (disable:4996)

#define TRUE 1

FPSData* fpsData;	//

char PLAYER_STR[] = "●";

typedef struct {
	int x, y;		// 플레이어 좌표
} Position;

typedef struct {
	Position position;		// 플레이어 좌표
	char* strPlayer;		// 플레이어 그래픽
	int playerLen;			// 플레이어 길이
} Player;

Player player;		// 플레이어 선언

void init()
{
	initFPSData(&fpsData);
	player.position.x = 2;		// 플레이어 초기 좌표
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

	// 왼쪽으로 벗어나는 경우 - 클리핑 기술 활용
	if (player.position.x < 2) {
		screenPrint(0, player.position.y, &player.strPlayer[0]);
		player.position.x += 2;
	}
	// 오른쪽으로 벗어나는 경우
	else if (123 < player.position.x + 1) {
		screenPrint(122, player.position.y, &player.strPlayer[0]);
		player.position.x -= 2;
	}
	// 아래쪽으로 벗어나는 경우
	else if (24 <= player.position.y) {
		screenPrint(24, player.position.x, &player.strPlayer[0]);
		player.position.y -= 1;
	}
	// 윗쪽으로 벗어나는 경우
	else if (player.position.y <= 1) {
		screenPrint(24, player.position.x, &player.strPlayer[0]);
		player.position.y += 1;
	}
	else {
		screenPrint(player.position.x, player.position.y, player.strPlayer);
	}


	sprintf(string, "캐릭터 이동 좌표: (%d, %d)", player.position.x, player.position.y);
	stage1();
	screenPrint(10, 0, string);
	screenFlipping();
}

// 동적 할당 해제
void release()
{
	destoyFPSData(&fpsData);
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

		keyProcess(nKey);		// 

		update();				// 데이터 업데이트

		render();				// 그래픽 렌더링
		waitRender(clock());
	}

	release();					// 동적할당 헤제
	screenRelease();			// 스크린 동적 할당 해제

	return 0;
}
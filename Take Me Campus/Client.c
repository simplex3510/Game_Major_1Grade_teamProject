#pragma warning (disable:4996)

#include <stdio.h>			// 표준 입출력 헤더
#include <conio.h>			// 입출력, 표준에서 벗어남

#include "screen.h"			// 렌더링 처리 헤더
#include "colide.h"			// 스테이지 별 충돌 체크
#include "maps.h"
#include "object.h"
#include "SoundManager.h"
#include "Timer.h"


#define TRUE 1
#define ESC 27

#define ARROW 224
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

int LOOP = TRUE;

clock_t curTime;
clock_t oldTime;

Player player;		// 플레이어 오브젝트 선언
Object potal;		// 포탈 오브젝트 선언
//Object platform[5];

static int stage = 1;


void init()
{
	player_init(&player);		// 플레이어 초기화
	potal_init(&potal, stage);	// 포탈 초기화
	/*for (int i = 0; i < 3; i++)
	{
		platform_init(&platform[i], i);
	}*/

	//initTimer();				// 타이머 초기화

	sound_init();				// FMOD 초기화
}

void update()
{
	curTime = clock() / 1000.0f;
	static int count = 0;
	//player.bounce.isJump = 1;

	int speed = 3;
	float dist = 1;

	// 즉, 최근 시간과 이전 시간을 빼면 시간차가 나오는데, 이게 일정 수준보다 커야함
	// -> 점프와 점프 사이의 시간적 간격 = 점프 속도
	// 점프와 점프사이의 시간차 < (최근시간 - 이전 시간)

	//updateTimer();

	//while (player.bounce.jumpTime < (curTime - player.bounce.oldTime)) {
	//
	//	// 최고점이 아니라면, 상승한다.
	//	if (player.bounce.isTop == 0) {
	//		player.position.y--;
	//		count++;
	//		// 최고점에 다랐을 경우, 
	//		if (count == 3) { player.bounce.isTop = 1; }
	//		player.bounce.oldTime = curTime;	// 점프 시점 시각 업데이트
	//
	//		return;
	//	}
	//	// 최고점이라면, 하강한다.
	//	else if (player.bounce.isTop == 1) {
	//		player.position.y++;
	//		count++;
	//		// 다시 내려왔을 경우
	//		if (count == 6) { player.bounce.isTop = 0; player.bounce.isJump = 0; count = 0; }
	//		player.bounce.oldTime = curTime;	// 점프 시점 시각 업데이트
	//		return;
	//	}
	//}

	//while (player.bounce.jumpTime < (curTime - player.bounce.oldTime))
	while (player.bounce.jumpTime < (curTime - oldTime)*1) {

		dist = speed * ((curTime - oldTime) * 1);

		// 최고점이 아니라면, 상승한다.
		if (player.bounce.isTop == 0) {
			player.position.y -= dist;
			count++;
			// 최고점에 다랐을 경우, 
			if (count == 3) { player.bounce.isTop = 1; }
			oldTime = curTime;    // 점프 시점 시각 업데이트

			return;
		}
		// 최고점이라면, 하강한다.
		else if (player.bounce.isTop == 1) {
			player.position.y += dist;
			count++;
			// 다시 내려왔을 경우
			if (count == 6) { player.bounce.isTop = 0; count = 0; }
			oldTime = curTime;    // 점프 시점 시각 업데이트

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

	// 포탈 충돌 체크, 다음 스테이지
	if ((player.position.x == potal.position.x) &&
		(player.position.y == potal.position.y)) {
		stage++;
		potal_position(&potal, stage);
	}

	// 스테이지 출력
	switch (stage)
	{
	case 1:
		stage1();
		break;
	case 2:
		stage2();
		/*for (int i = 0; i < 3; i++) {
			screenPrint(platform[i].position.x, platform[i].position.y, platform[i].strobject);
			stage2Colide(&player, &platform[i]);
		}*/
		break;
	case 3:
		stage3();
		break;
	case 4:
		stageEnding();
		screenPrint(25, 25, "Good Choice!");
		//LOOP = FALSE;
		break;
	default:
		stage1();
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
		screenPrint(potal.position.x, potal.position.y, potal.strobject);		// 포탈 렌더링
		screenPrint(player.position.x, player.position.y, player.strobject);	// 플레이어 렌더링
	}

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
		waitRender(clock());
	}

	release();					// 동적할당 헤제
	screenRelease();			// 스크린 해제
	sound_release();			// FMOD 종료

	printf("Thank you for your playing!");

	return 0;
}


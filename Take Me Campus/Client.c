#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <malloc.h>
#include <windows.h>

#include "screen.h"

#pragma warning (disable:4996)

#define TRUE 1

clock_t FPSCurTime, FPSOldTime;
int FrameCnt;
char* FPSTextBuffer;


//void input_key()
//{
//	int key;
//	while (TRUE) {
//
//		if (_kbhit()) {
//
//			key = getch();
//			if (key == 224) {
//				key = _getch();
//
//				switch (key) {
//				case 72:
//					printf("↑");
//					break;
//				case 80:
//					printf("↓");
//					break;
//				case 75:
//					printf("←");
//					break;
//				case 77:
//					printf("→");
//					break;
//				}
//			}
//		}
//	}
//
//	return;
//}

void init()
{
	FrameCnt = 0;
	FPSTextBuffer = (char*)malloc(sizeof(char) * 10);
	sprintf(FPSTextBuffer, "FPS:%d", FrameCnt);
	FPSOldTime = clock();
}

void update()
{

}

void render()
{
	screenClear();

	FrameCnt++;
	FPSCurTime = clock();

	if (FPSCurTime - FPSOldTime >= 1000)
	{
		sprintf(FPSTextBuffer, "FPS:%d", FrameCnt);
		FPSOldTime = clock();
		FrameCnt = 0;
	}

	screenPrint(0, 0, FPSTextBuffer);

	screenFlipping();

}

// 화면 출력 함수
void release()
{
	free(FPSTextBuffer);
}

int main()
{
	int key;

	// 틱을 저장하는 형식
	clock_t curTime, oldTime;

	screenInit();
	init();

	while (TRUE) {
		
		if (_kbhit()) {
			key = getch();
			if (key == 224) {
				key = getch();

				switch (key) {
				case 72:
					printf("↑");
					break;
				case 80:
					printf("↓");
					break;
				case 75:
					printf("←");
					break;
				case 77:
					printf("→");
					break;
				}
			}
		}

		oldTime = clock();						// (프로그램이 시작될 때부터 지난 틱의 수 반환) = (렌더 전의 시간을 입력, 이후 대기 상태)
		

		update();	// 데이터 업데이트
		render();	// 그래픽 렌더링

		while (TRUE) {
			
			curTime = clock();					// 렌더 후의 시간을 지속적으로 갱신
			if (33 < curTime - oldTime)			// 두 시간의 차가 33ms일 때 대기상태 탈출
				break;
		}
	}

	release();	// 해제
	screenRelease();

	return 0;


	/*system("cls");
	system("title Take Me Campus");
	system("mode con cols=122 lines=40");
	system("color F0");

	stage1();

	input_key();


	return 0;*/
}
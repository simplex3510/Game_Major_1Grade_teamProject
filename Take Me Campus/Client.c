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
//					printf("��");
//					break;
//				case 80:
//					printf("��");
//					break;
//				case 75:
//					printf("��");
//					break;
//				case 77:
//					printf("��");
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

// ȭ�� ��� �Լ�
void release()
{
	free(FPSTextBuffer);
}

int main()
{
	int key;

	// ƽ�� �����ϴ� ����
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
					printf("��");
					break;
				case 80:
					printf("��");
					break;
				case 75:
					printf("��");
					break;
				case 77:
					printf("��");
					break;
				}
			}
		}

		oldTime = clock();						// (���α׷��� ���۵� ������ ���� ƽ�� �� ��ȯ) = (���� ���� �ð��� �Է�, ���� ��� ����)
		

		update();	// ������ ������Ʈ
		render();	// �׷��� ������

		while (TRUE) {
			
			curTime = clock();					// ���� ���� �ð��� ���������� ����
			if (33 < curTime - oldTime)			// �� �ð��� ���� 33ms�� �� ������ Ż��
				break;
		}
	}

	release();	// ����
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
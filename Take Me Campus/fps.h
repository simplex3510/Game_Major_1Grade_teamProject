#include<malloc.h>
#include<stdio.h>
#include<time.h>

#pragma once
#pragma warning (disable:4996)

/* clock()   = ���α׷��� ���۵� ������ ���� �ð�(����ms, clock ��)�� ��ȯ
   clock_t() = �ð�(ƽ ��)�� �����ϴ� ����, long�� typedef ���̴�.*/

// FPSData �ڷ��� ����
typedef struct
{
    /* ������ ������ ���� 2���� �ð� ���� ����
       �� �ð��� ���� (16ms - 60 fps) or (33ms - 30fps)�� �� ������ Ż�� */
    clock_t fpsCurTime, fpsOldTime;
    int frameCnt;
    char* fpsTextBuffer;
}FPSData;

// FPS������ �ʱ�ȭ
void initFPSData(FPSData** fpsData);

// FPS ���
void drawFPS(FPSData** fpsData);

// Free
void destoyFPSData(FPSData** fpsData);
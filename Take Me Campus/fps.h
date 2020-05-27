#include<malloc.h>
#include<stdio.h>
#include<time.h>

#pragma once
#pragma warning (disable:4996)

/* clock()   = 프로그램이 시작될 때부터 지난 시간(단위ms, clock 수)을 반환
   clock_t() = 시간(틱 수)을 저장하는 형식, long의 typedef 형이다.*/

// FPSData 자료형 정의
typedef struct
{
    /* 프레임 조절을 위한 2개의 시간 변수 선언
       두 시간의 차가 (16ms - 60 fps) or (33ms - 30fps)일 때 대기상태 탈출 */
    clock_t fpsCurTime, fpsOldTime;
    int frameCnt;
    char* fpsTextBuffer;
}FPSData;

// FPS데이터 초기화
void initFPSData(FPSData** fpsData);

// FPS 출력
void drawFPS(FPSData** fpsData);

// Free
void destoyFPSData(FPSData** fpsData);
#include"fps.h"
#include "screen.h"

#pragma once
#pragma warning (disable:4996)


void initFPSData(FPSData** fpsData)
{
    // (fpsData의 현재 값) = 
    (*fpsData) = (FPSData*)malloc(sizeof(FPSData));
    (*fpsData)->frameCnt = 0;
    (*fpsData)->fpsTextBuffer = (char*)malloc(sizeof(char) * 10);
    sprintf((*fpsData)->fpsTextBuffer, "FPS:%d", (*fpsData)->frameCnt);
    (*fpsData)->fpsOldTime = clock();

}

void drawFPS(FPSData** fpsData)
{
    //출력코드
    (*fpsData)->frameCnt++;
    (*fpsData)->fpsCurTime = clock();
    if ((*fpsData)->fpsCurTime - (*fpsData)->fpsOldTime >= 1000)
    {
        sprintf((*fpsData)->fpsTextBuffer, "FPS:%d", (*fpsData)->frameCnt);
        (*fpsData)->fpsOldTime = clock();
        (*fpsData)->frameCnt = 0;
    }

    screenPrint(0, 0, (*fpsData)->fpsTextBuffer);
}

void destoyFPSData(FPSData** fpsData)
{
    free((*fpsData)->fpsTextBuffer);
    free(*fpsData);
}
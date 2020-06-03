//#include"fps.h"
//#include "screen.h"
//
//#pragma once
//#pragma warning (disable:4996)
//
///* FPSData를 구조체 포인터로 선언한 이유 **********
//* 
//* 1. fps의 수는 항상 바뀐다. 따라서 동적으로 메모리를 할당해 주어야 한다.
//*
//*
//***************************************************/
//
//
//// Call-by-Refernce
//// FPS데이터 초기화(포인터 형식으로 선언했으니, 해당 포인터를 인자로 받을 때 더블 포인터를 사용하여 접근함)
//void initFPSData(FPSData** fpsData)
//{
//    // fpsData라는 구조체 포인터의 전체적인 메모리 공간을 마련함.
//    (*fpsData) = (FPSData*)malloc(sizeof(FPSData));
//    // 프레임 수 카운트 초기화
//    (*fpsData)->frameCnt = 0;
//    // 출력 버퍼를 동적으로 할당받음
//    (*fpsData)->fpsTextBuffer = (char*)malloc(sizeof(char) * 10);
//    // 저장한다 (버퍼에, 문자열을 , 카운트 값을 받아와서)
//    sprintf((*fpsData)->fpsTextBuffer, "FPS:%d", (*fpsData)->frameCnt);
//    // 이전 시각 초기화
//    (*fpsData)->fpsOldTime = clock();
//
//}
//
//// FPS 출력
//void drawFPS(FPSData** fpsData)
//{
//    // 프레임 카운트 증가
//    (*fpsData)->frameCnt++;
//    // 현재 출력 시각 업데이트
//    (*fpsData)->fpsCurTime = clock();
//
//    
//    // if의 과정은 1초마다 fps를 업데이트 하기 위함임.
//    // (화면 출력 시간의 간격 = 하나의 화면(버퍼)이 보여지는 시간)이 1초(1000)보다 커지면
//    if (1000 <= (*fpsData)->fpsCurTime - (*fpsData)->fpsOldTime)
//    {
//        // 다시 저장한다 (버퍼에, 문자열을 , 카운트 값을 받아와서)
//        sprintf((*fpsData)->fpsTextBuffer, "FPS:%d", (*fpsData)->frameCnt);
//        // 이전 화면 출력 시간 업데이트
//        (*fpsData)->fpsOldTime = clock();
//        // 프레임 카운트를 다시 받아오기 위해 0으로 초기화
//        (*fpsData)->frameCnt = 0;
//    }
//    
//    // (0, 0)의 좌표에 해당 버퍼(문자열)를 출력한다.
//    screenPrint(0, 0, (*fpsData)->fpsTextBuffer);
//}
//
//// FPSData 동적 할당 해제
//void freeFPSData(FPSData** fpsData)
//{
//    free((*fpsData)->fpsTextBuffer);
//    free(*fpsData);
//}
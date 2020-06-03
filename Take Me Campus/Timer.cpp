//#include "stdafx.h"
//#include <Windows.h>
//#include "Timer.h"
//
//float prevTime  = 0;
//float currTime  = 0;
//float deltaTime = 0;
//float timeScale = 1.0f;
//
//void initTimer()  //타이머 초기화 함수
//{
//	//////tick 카운트 구하기/////	
//	prevTime = (float)GetTickCount() / 1000.0f;  //이전 장면 시간 
//	currTime = (float)GetTickCount() / 1000.0f;  //현재 장면 시간
//	deltaTime = 0; //장면간의 시간차
//}
//
//void updateTimer()
//{
//	currTime = (float)GetTickCount() / 1000.0f;   //현재 장면시간
//	deltaTime = currTime - prevTime;			  //장면간 시간차
//	prevTime = currTime;						  //현재 장면의 시간은 다음 장면의 이전시간으로 저장 
//
//}
//
//void exitTimer()
//{
//   //할거없음..
//}
//
//float getDeltaTime()
//{
//	return deltaTime * timeScale;
//}
//
//float getUnScaledDeltaTime()
//{
//	return deltaTime;
//}
//
//void setTimeScale(float scale)
//{
//    timeScale = scale;
//}

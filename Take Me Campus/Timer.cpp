//#include "stdafx.h"
//#include <Windows.h>
//#include "Timer.h"
//
//float prevTime  = 0;
//float currTime  = 0;
//float deltaTime = 0;
//float timeScale = 1.0f;
//
//void initTimer()  //Ÿ�̸� �ʱ�ȭ �Լ�
//{
//	//////tick ī��Ʈ ���ϱ�/////	
//	prevTime = (float)GetTickCount() / 1000.0f;  //���� ��� �ð� 
//	currTime = (float)GetTickCount() / 1000.0f;  //���� ��� �ð�
//	deltaTime = 0; //��鰣�� �ð���
//}
//
//void updateTimer()
//{
//	currTime = (float)GetTickCount() / 1000.0f;   //���� ���ð�
//	deltaTime = currTime - prevTime;			  //��鰣 �ð���
//	prevTime = currTime;						  //���� ����� �ð��� ���� ����� �����ð����� ���� 
//
//}
//
//void exitTimer()
//{
//   //�Ұž���..
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

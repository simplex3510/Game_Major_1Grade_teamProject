#pragma once
#pragma warning (disable:4996)

#include <windows.h>

// ȭ�� ���� �ʱ�ȭ, ������ ���� ���� 2�� ����
void screenInit();

// ���� ����� ���� ȭ�� Ŭ����
void screenClear();

// Ȱ��ȭ�� ���ۿ� ��Ȱ��ȭ�� ������ ���¸� ��ȯ
void screenFlipping();

// ������ 2���� ���۸� ��� ����
void screenRelease();

// x, y��ǥ�� string ���
void screenPrint(int x, int y, char* string);

// ȭ�鿡 ����� ���� ���� ����
void setColor(unsigned short color);
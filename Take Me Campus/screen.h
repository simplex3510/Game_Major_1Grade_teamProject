#pragma once
#pragma warning (disable:4996)

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

// Ÿ��Ʋ
void title();
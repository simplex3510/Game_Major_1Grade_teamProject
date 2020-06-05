#pragma once
#pragma warning (disable:4996)

#include "screen.h"


/*
static�� ��� ���
 1. ���α׷��� ����Ǵ� ���ȿ� ����ؼ� �����ؾ� �� ������ �ʿ�
 2. �� ������ �����ϴ� ������ �ϳ��� �Լ� �� ��

 static ���� ������ ���
 1. ����ƽ ���� ������ �ش� ���� �������� �����ϱ� ���� �����.
    
    => �� �Ʒ��� �� ������ �׻� �����Ǹ�, screen.c ������ �����Ѵ�.
*/

/* HANDLE�� �ǹ�
* 1. �ü���� �����ϱ� ���ؼ� �����͸� ����� �� ����
* 2. ������ ��ſ� 'HANDLE(�ڵ�)'�̶�� ������ �����.
* 3. �ڵ��� �ü�� ���ο� �ִ� � ���ҽ��� �ּҸ� ������ ġȯ�� ���̴�.
* 4. HANDLE = unsigned int
*  => �� �ڵ��� �ü�� ���ҽ��� �����ϰ� �����ϱ� ���ؼ� ������ ��� ������ �� �ִ� ����
*/


static int g_nScreenIndex;      // ��� ���� �ε��� ����
static HANDLE g_hScreen[2];     // ���� ���ۿ� �迭 (ũ�� 2 = 2��)

// ��ũ�� �ʱ�ȭ(�ʱ� ����)
void screenInit()
{
    system("title Take Me Campus");             // �ܼ�â �̸� ����
    system("mode con cols=127 lines=32");       // cols(����), line(����)
    system("color F0");                         // �ܼ� ��� ���� ���� (��� - �� / ���� - ��)

    CONSOLE_CURSOR_INFO cci;                    // �ܼ��� Ŀ���� ���� ������ ���� ���� ����

    // ȭ�� ���� ���� �� ����
    // �Ű� ���� = (�ܼ� ȭ�� ���ۿ� ���� �׼���, ���� ���� ����, ����� ����, ������ �ܼ� ȭ�� ���� ����, Reserved; should be NULL.)
    g_hScreen[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,
        0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    g_hScreen[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,
        0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

    //Ŀ�� ���� ���� - �����
    cci.dwSize = 1;                                     // Ŀ���� ä������ ���� ���� ����(1~100) - 1��ŭ
    cci.bVisible = FALSE;                               // ȭ�� ǥ�� ���� - �� ��

    // ������ ��ũ�� ���ۿ� ������ Ŀ���� ������ ����.
    // ���� �Ѵ� cci ������ ���� ���� - Ŀ�� ��� �� ��
    SetConsoleCursorInfo(g_hScreen[0], &cci);           
    SetConsoleCursorInfo(g_hScreen[1], &cci);           
}

// ���� ����(��ȯ)
void screenFlipping()
{
    // ���޹��� ���۸� ȭ�鿡 ���
    SetConsoleActiveScreenBuffer(g_hScreen[g_nScreenIndex]);

    // �ٸ� ���� ����� ���� �ε��� �� ��ȯ
    g_nScreenIndex = !g_nScreenIndex;
}

// ��ũ�� Ŭ����
void screenClear()
{
    // COORD�� ��ǥ���� ������ �� �ִ� ����ü
    COORD Coor = { 0,0 };
    // dw���� ���ۿ� ���� ��ϵ� ���ڼ��� �޴� ���� ������
    DWORD dw;
    // ���ۿ�, (����)�� ä���, 80*25 ��ŭ, (0, 0)(Coor)���� �����Ͽ�
    FillConsoleOutputCharacter(g_hScreen[g_nScreenIndex], ' ', 123 * 33, Coor, &dw);
    
}

// ȭ�� ����
void screenRelease()
{
    /* �ڵ� ������ ���Ͽ�
    * 1. �ڵ� ������ ������� �ʴ� �ڵ��� �������� ���� �� �߻�
    * 2. ������ ����Ʈ���� ������ �� �����̴�.
    * 3. Ư�� �Ⱓ���� ����, �ݺ������� �Ͼ�� ��� -> �ټ��� �ڵ���� ��� ������ ǥ�õǰ� ����� �� ���Ե�
    *     -> �ᱹ ���� ������ �浹�� ����Ŵ
    */


    // ���� 2�� �� �ݱ�
    CloseHandle(g_hScreen[0]);
    CloseHandle(g_hScreen[1]);
}

// ������ ��ǥ�� string�� ���
void screenPrint(int x, int y, char* string)
{
    // dw���� ���ۿ� ���� ��ϵ� ���ڼ��� �޴� ���� ������
    DWORD dw;
    // Ŀ���� ��ġ
    COORD CursorPosition = { x, y };

    // Ŀ�� ��ġ���� ���ڿ� ����ϱ� ���� Ŀ�� ��ġ ����
    // Ŀ���� ����� ����, ��ǥ ����
    SetConsoleCursorPosition(g_hScreen[g_nScreenIndex], CursorPosition);

    // ���ڿ��� ȭ�鿡 ���
    // ���� ����, ����� ��Ʈ��, ��Ʈ�� ����, dw������, �񵿱� ����� �̻��
    WriteFile(g_hScreen[g_nScreenIndex], string, strlen(string), &dw, NULL);
}

// ���� ����
void setColor(unsigned short color)
{
    // ���� ����, ���� ����
    SetConsoleTextAttribute(g_hScreen[g_nScreenIndex], color);
}
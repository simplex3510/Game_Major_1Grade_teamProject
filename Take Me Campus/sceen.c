#include <windows.h>

#pragma once
#pragma warning (disable:4996)

/*
static�� ��� ���
 1. ���α׷��� ����Ǵ� ���ȿ� ����ؼ� �����ؾ� �� ������ �ʿ�
 2. �� ������ �����ϴ� ������ �ϳ��� �Լ� �� ��
    
    => �� �Ʒ��� �� ������ �׻� �����Ǹ�, screen.c ������ �����Ѵ�.
*/

static int g_nScreenIndex;      // ��� ���� �ε��� ����
static HANDLE g_hScreen[2];     // ���� ���ۿ� �迭 (ũ�� 2 = 2��)

// ��ũ�� �ʱ�ȭ(�ʱ� ����)
void screenInit()
{
    system("title Take Me Campus");
    system("mode con cols=127 lines=32");       // cols(����), line(����)
    system("color F0");

    CONSOLE_CURSOR_INFO cci;

    // ȭ�� ���� ���� �� ����
    // �Ű� ���� = (�ܼ� ȭ�� ���ۿ� ���� �׼���, ���� ���� ����, ����� ����, )
    g_hScreen[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,
        0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    g_hScreen[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,
        0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

    //Ŀ�� �����
    cci.dwSize = 1;                                     // Ŀ���� ä������ ���� ���� ����(1~100) - 1��ŭ
    cci.bVisible = FALSE;                               // ȭ�� ǥ�� ���� - �� ��
    SetConsoleCursorInfo(g_hScreen[0], &cci);           // ������ ��ũ�� ���ۿ� ������ Ŀ���� ������ ����.
    SetConsoleCursorInfo(g_hScreen[1], &cci);           // ���� �Ѵ� cci ������ ���� ���� - Ŀ�� ��� �� ��
}

// ���� ����
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
    // ���� 2�� �� ����
    CloseHandle(g_hScreen[0]);
    CloseHandle(g_hScreen[1]);
}

// ������ ��ǥ�� string�� ���
void screenPrint(int x, int y, char* string)
{
    // dw���� ���ۿ� ���� ��ϵ� ���ڼ��� �޴� ���� ������
    DWORD dw;
    COORD CursorPosition = { x, y };
    // Ŀ���� ����� ���ۿ� ��ǥ ����
    SetConsoleCursorPosition(g_hScreen[g_nScreenIndex], CursorPosition);
    // ���� ����, ����� ��Ʈ��, ��Ʈ�� ����, dw������, �񵿱� ����� �̻��
    WriteFile(g_hScreen[g_nScreenIndex], string, strlen(string), &dw, NULL);
}

// ���� ����
void setColor(unsigned short color)
{
    // ���� ����, ���� ����
    SetConsoleTextAttribute(g_hScreen[g_nScreenIndex], color);
}
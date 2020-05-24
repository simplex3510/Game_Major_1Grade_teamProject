#include <windows.h>

static int g_nScreenIndex;      // 출력 버퍼 인덱스 변수
static HANDLE g_hScreen[2];     // 더블 버퍼용 배열 (크기 2 = 2개)

// 스크린 초기화(초기 설정)
void screenInit()
{
    CONSOLE_CURSOR_INFO cci;

    //화면 버퍼 2개를 만든다.
    g_hScreen[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,
        0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    g_hScreen[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,
        0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

    //커서 숨기기
    cci.dwSize = 1;                                     // 커서로 채워지는 문자 셀의 비율(1~100) - 1만큼
    cci.bVisible = FALSE;                               // 화면 표시 여부 - 안 함
    SetConsoleCursorInfo(g_hScreen[0], &cci);           // 생성한 스크린 버퍼에 정의한 커서의 정보를 설정.
    SetConsoleCursorInfo(g_hScreen[1], &cci);           // 버퍼 둘다 cci 설정을 전달 받음 - 커서 출력 안 함
}

// 버퍼 스왑
void screenFlipping()
{
    // 전달받은 버퍼를 화면에 출력
    SetConsoleActiveScreenBuffer(g_hScreen[g_nScreenIndex]);
    // 다른 버퍼 출력을 위해 인덱스 값 변환
    g_nScreenIndex = !g_nScreenIndex;
}

// 스크린 클리어
void screenClear()
{
    COORD Coor = { 0,0 };
    // dw값은 버퍼에 실제 기록된 문자수를 받는 변수 포인터
    DWORD dw;
    // 버퍼에, (공백)을 채운다, 80*25 만큼, (0, 0)(Coor)부터 시작하여
    FillConsoleOutputCharacter(g_hScreen[g_nScreenIndex], ' ', 80 * 25, Coor, &dw);     
}

// 화면 해제
void screenRelease()
{
    // 버퍼 2개 다 해제
    CloseHandle(g_hScreen[0]);
    CloseHandle(g_hScreen[1]);
}

// 설정한 좌표에 string을 출력
void screenPrint(int x, int y, char* string)
{
    // dw값은 버퍼에 실제 기록된 문자수를 받는 변수 포인터
    DWORD dw;
    COORD CursorPosition = { x, y };
    // 커서를 출력할 버퍼와 좌표 설정
    SetConsoleCursorPosition(g_hScreen[g_nScreenIndex], CursorPosition);
    // 버퍼 지정, 출력할 스트링, 스트링 길이, dw포인터, 비동기 입출력 미사용
    WriteFile(g_hScreen[g_nScreenIndex], string, strlen(string), &dw, NULL);
}

// 색상 설정
void setColor(unsigned short color)
{
    // 버퍼 지정, 색상 설정
    SetConsoleTextAttribute(g_hScreen[g_nScreenIndex], color);
}
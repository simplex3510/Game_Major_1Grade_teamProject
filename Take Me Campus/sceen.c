#pragma once
#pragma warning (disable:4996)

#include "screen.h"


/*
static의 사용 경우
 1. 프로그램이 실행되는 동안에 계속해서 유지해야 할 변수가 필요
 2. 그 변수에 접근하는 영역이 하나의 함수 일 때

 static 전역 변수의 경우
 1. 스태틱 전역 변수는 해당 파일 내에서만 접근하기 위해 사용함.
    
    => ∴ 아래의 두 변수는 항상 유지되며, screen.c 에서만 접근한다.
*/

/* HANDLE의 의미 *******************************************************************************\
* 1. 운영체제에 접근하기 위해서 포인터를 사용할 수 없음                                         *
* 2. 포인터 대신에 'HANDLE(핸들)'이라는 개념을 사용함.                                          *
* 3. 핸들은 운영체제 내부에 있는 어떤 리소스의 주소를 정수로 치환한 값이다.                     *
* 4. HANDLE = unsigned int                                                                      *
*  => ∴ 핸들은 운영체제 리소스를 안전하게 관리하기 위해서 포인터 대신 접근할 수 있는 개념       *
\***********************************************************************************************/


static int g_nScreenIndex;      // 출력 버퍼 인덱스 변수
static HANDLE g_hScreen[2];     // 더블 버퍼용 배열 (크기 2 = 2개)

// 스크린 초기화(초기 설정)
void screenInit()
{
    system("title Take Me Campus");             // 콘솔창 이름 설정
    system("mode con cols=127 lines=32");       // cols(가로), line(세로)
    system("color F0");                         // 콘솔 출력 색상 설정 (배경 - 흰 / 문자 - 검)

    CONSOLE_CURSOR_INFO cci;                    // 콘솔의 커서에 대한 정보를 담을 변수 선언

    // 화면 버퍼 생성 및 설정
    // 매개 변수 = (콘솔 화면 버퍼에 대한 액세스, 버퍼 공유 여부, 상속의 여부, 생성할 콘솔 화면 버퍼 유형, Reserved; should be NULL.)
    g_hScreen[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,
        0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    g_hScreen[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,
        0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

    //커서 정보 설정 - 숨기기
    cci.dwSize = 1;                                     // 커서로 채워지는 문자 셀의 비율(1~100) - 1만큼
    cci.bVisible = FALSE;                               // 화면 표시 여부 - 안 함

    // 생성한 스크린 버퍼에 정의한 커서의 정보를 설정.
    // 버퍼 둘다 cci 설정을 전달 받음 - 커서 출력 안 함
    SetConsoleCursorInfo(g_hScreen[0], &cci);           
    SetConsoleCursorInfo(g_hScreen[1], &cci);           
}

// 버퍼 스왑(전환)
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
    // COORD는 좌표값을 저장할 수 있는 구조체
    COORD Coor = { 0,0 };
    // dw값은 버퍼에 실제 기록된 문자수를 받는 변수 포인터
    DWORD dw;
    // 버퍼에, (공백)을 채운다, 80*25 만큼, (0, 0)(Coor)부터 시작하여
    FillConsoleOutputCharacter(g_hScreen[g_nScreenIndex], ' ', 123 * 33, Coor, &dw);
    
}

// 화면 해제
void screenRelease()
{
    /* 핸들 누수에 관하여
    * 1. 핸들 누수는 사용하지 않는 핸들을 놓아주지 않을 때 발생
    * 2. 일종의 소프트웨어 버그의 한 종류이다.
    * 3. 특정 기간동안 자주, 반복적으로 일어나는 경우 -> 다수의 핸들들이 사용 중으로 표시되고 사용할 수 없게됨
    *     -> 결국 성능 문제나 충돌을 일으킴
    */


    // 버퍼 2개 다 닫기
    CloseHandle(g_hScreen[0]);
    CloseHandle(g_hScreen[1]);
}

// 설정한 좌표에 string을 출력
void screenPrint(int x, int y, char* string)
{
    // dw값은 버퍼에 실제 기록된 문자수를 받는 변수 포인터
    DWORD dw;
    // 커서의 위치
    COORD CursorPosition = { x, y };

    // 커서 위치에서 문자열 출력하기 위해 커서 위치 설정
    // 커서를 출력할 버퍼, 좌표 전달
    SetConsoleCursorPosition(g_hScreen[g_nScreenIndex], CursorPosition);

    // 문자열을 화면에 출력
    // 버퍼 지정, 출력할 스트링, 스트링 길이, dw포인터, 비동기 입출력 미사용
    WriteFile(g_hScreen[g_nScreenIndex], string, strlen(string), &dw, NULL);
}

// 색상 설정
void setColor(unsigned short color)
{
    // 버퍼 지정, 색상 설정
    SetConsoleTextAttribute(g_hScreen[g_nScreenIndex], color);
}
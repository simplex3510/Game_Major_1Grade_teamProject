// 화번 버퍼 초기화, 전위와 후위 버퍼 2개 생성
void ScreenInit();

// 다음 장면을 위한 화면 클리어
void ScreenClear();

// 활성화된 버퍼와 비활성화된 버퍼의 상태를 전환
void ScreenFlipping();

// 생성한 2개의 버퍼를 모두 해제
void ScreenRelease();

// x, y와표에 string 출력
void ScreenPrint(int x, int y, char* string);

// 화면에 출력할 문자 색상값 지정
void SetColor(unsigned short color);
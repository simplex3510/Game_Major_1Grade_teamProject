#include "object.h"
#include "screen.h"


void wallColide(Player* player)
{
	// 왼쪽으로 벗어나는 경우 - 클리핑 기술 활용
	if (player->position.x < 2) {
		screenPrint(2, player->position.y, player->strobject);
		player->position.x = 2;
	}
	// 오른쪽으로 벗어나는 경우
	else if (122 < player->position.x) {
		screenPrint(122, player->position.y, player->strobject);
		player->position.x = 122;
	}
	// 아래쪽으로 벗어나는 경우
	else if (29 < player->position.y) {
		screenPrint(player->position.x, 29, player->strobject);
		player->position.y = 29;
	}
	// 윗쪽으로 벗어나는 경우
	else if (player->position.y < 2) {
		screenPrint(player->position.x, 2, player->strobject);
		player->position.y = 2;
	}
}

int stage2Colide(Player* player, Object* platfrom)
{
	if ((player->position.x == platfrom->position.x) &&
		(player->position.y > platfrom->position.y)) {
		player->position.x += 2;

		return TRUE;
	}

	if ((player->position.x <= platfrom->position.x) &&
		(player->position.y > platfrom->position.y - 1)) {
		player->position.y--;

		return platfrom->isColide;	// 플랫폼과 충돌했으니 TRUE를 반환
	}
}

void bounce(Player* player, Object* platform)
{
	clock_t curTime = clock();
	static int count = 0;


	// 즉, 최근 시간과 이전 시간을 빼면 시간차가 나오는데, 이게 일정 수준보다 커야함
	// -> 점프와 점프 사이의 시간적 간격 = 점프 속도
	// 점프와 점프사이의 시간차 < (최근시간 - 이전 시간)

	// 최고점이 아니라면, 상승한다.
	if ((player->bounce.isJump == TRUE) && (player->bounce.isTop == FALSE)) {
		player->position.y--;
		count++;
		// 최고점에 달았을 경우, 
		if (count == JUMP_SIZE) { player->bounce.isTop = TRUE; }
		player->bounce.oldTime = curTime;	// 점프 시점 시각 업데이트
		return;
	}

	// 최고점이라면, 하강한다.
	else if (player->bounce.isTop == TRUE) {
		player->position.y++;
		count++;
		// 지면으로 내려왔을 경우
		if (count == JUMP_SIZE*2) {
			player->bounce.isJump = TRUE;
			player->bounce.isTop = FALSE;
			count = 0;
		}
		player->bounce.oldTime = curTime;	// 점프 시점 시각 업데이트
		return;
	}


}
#include "object.h"
#include "screen.h"


void wallColide(Player* player)
{
	// �������� ����� ��� - Ŭ���� ��� Ȱ��
	if (player->position.x < 2) {
		screenPrint(2, player->position.y, player->strobject);
		player->position.x = 2;
	}
	// ���������� ����� ���
	else if (122 < player->position.x) {
		screenPrint(122, player->position.y, player->strobject);
		player->position.x = 122;
	}
	// �Ʒ������� ����� ���
	else if (29 < player->position.y) {
		screenPrint(player->position.x, 29, player->strobject);
		player->position.y = 29;
	}
	// �������� ����� ���
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

		return platfrom->isColide;	// �÷����� �浹������ TRUE�� ��ȯ
	}
}

void bounce(Player* player, Object* platform)
{
	clock_t curTime = clock();
	static int count = 0;


	// ��, �ֱ� �ð��� ���� �ð��� ���� �ð����� �����µ�, �̰� ���� ���غ��� Ŀ����
	// -> ������ ���� ������ �ð��� ���� = ���� �ӵ�
	// ������ ���������� �ð��� < (�ֱٽð� - ���� �ð�)

	// �ְ����� �ƴ϶��, ����Ѵ�.
	if ((player->bounce.isJump == TRUE) && (player->bounce.isTop == FALSE)) {
		player->position.y--;
		count++;
		// �ְ����� �޾��� ���, 
		if (count == JUMP_SIZE) { player->bounce.isTop = TRUE; }
		player->bounce.oldTime = curTime;	// ���� ���� �ð� ������Ʈ
		return;
	}

	// �ְ����̶��, �ϰ��Ѵ�.
	else if (player->bounce.isTop == TRUE) {
		player->position.y++;
		count++;
		// �������� �������� ���
		if (count == JUMP_SIZE*2) {
			player->bounce.isJump = TRUE;
			player->bounce.isTop = FALSE;
			count = 0;
		}
		player->bounce.oldTime = curTime;	// ���� ���� �ð� ������Ʈ
		return;
	}


}
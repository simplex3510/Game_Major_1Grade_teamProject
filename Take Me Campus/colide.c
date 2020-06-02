#include "colide.h"

void stage2Colide(Player* player, Object* platfrom)
{
	if ((player->position.x == platfrom->position.x) &&
		(player->position.y > platfrom->position.y)) {
		player->position.x += 2;
	}

	if ((player->position.x <= platfrom->position.x) &&
		(player->position.y > platfrom->position.y - 1)) {
		player->position.y--;

	}
}
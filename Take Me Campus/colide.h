#pragma once

void wallColide(Player* player);

int stage1Colide(Object* flatfrom, Player* player);
void stage2Colide(Object* flatfrom, Player* player);
void stage3Colide(Object* flatfrom, Player* player);
void stage4Colide(Object* flatfrom, Player* player);

void bounce(Player* player);
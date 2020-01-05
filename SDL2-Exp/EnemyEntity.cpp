#include "EnemyEntity.h"

void EnemyEntity::tick()
{
	ticks++;
	if (ticks % 10 == 0) {
		moveEnemy();
		update();
		ticks = 0;
	}
}

void EnemyEntity::moveEnemy()
{
	if (target == nullptr) 
		changeVectors((rand() % 3) - 1.0, (rand() % 3) - 1.0);
	else 
		changeVectors((-rect.x + (double)target->getRect()->x) / 10.0 , (-rect.y + (double)target->getRect()->y) / 10.0);
}

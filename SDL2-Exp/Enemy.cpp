#include "Enemy.h"

void Enemy::tick()
{
	moveEnemy();
}

void Enemy::moveEnemy()
{
	if (target == nullptr) 
		changeVectors((rand() % 3) - 1.0, (rand() % 3) - 1.0);
	else 
		changeVectors((-rect.x + (double)target->getRect()->x) , (-rect.y + (double)target->getRect()->y));
}

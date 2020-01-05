#include "Enemy.h"

void Enemy::update()
{
	rotation = vect.dirTravel;
}

void Enemy::onColide(Element* colWith)
{
	dead = true;
}

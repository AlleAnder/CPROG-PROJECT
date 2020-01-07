#include "Enemy.h"

void Enemy::update()
{
	rotation = vect.dirTravel;
}

void Enemy::onColide(Element* colWith){
	health -= 1;
	Mix_PlayChannel(-1, collision, 0);
	if (health <= 0)
		dead = true;
}

#include "Enemy.h"

void Enemy::update()
{
	rotation = vect.dirOTravel();
}

void Enemy::onColide(Element* colWith){
	health -= 1;
	Mix_PlayChannel(-1, collision, 0);
	if (health <= 0) {
		dead = true;
		Mix_PlayChannel(-1, death, 0);
	}
		
}

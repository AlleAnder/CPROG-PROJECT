#include "Enemy.h"

Enemy::Enemy(int x, int y, int w, int h, int health, int strength) : EnemyEntity(x, y, w, h, 2) {
	this->health = health;
	this->strength = strength;
}

void Enemy::update()
{
	rotation = vect.dirTravel;
}

void Enemy::onColide(Element* colWith){

	dead = true;
}

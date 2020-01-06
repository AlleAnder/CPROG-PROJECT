#pragma once
#include "EnemyEntity.h"
class Enemy : public EnemyEntity
{
public:
	Enemy(int x, int y, int w, int h, int health, int strength);
	~Enemy() {};

	void update();
	void onColide(Element* colWith);
};





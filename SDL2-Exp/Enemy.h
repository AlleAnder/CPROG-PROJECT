#pragma once
#include "EnemyEntity.h"
class Enemy : public EnemyEntity
{
public:
	Enemy(int x, int y, int w, int h) : EnemyEntity(x, y, w, h, 2) {};
	~Enemy() {};

	void update();
	void onColide(Element* colWith);
};





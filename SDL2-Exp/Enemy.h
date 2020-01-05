#pragma once
#include "EnemyEntity.h"
class Enemy : public EnemyEntity
{
public:
	Enemy(int x, int y, int w, int h, int ELEMENT_ID) : EnemyEntity(x, y, w, h, ELEMENT_ID) {};
	~Enemy() {};

	void update();
	void onColide(Element* colWith);
};





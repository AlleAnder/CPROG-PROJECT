#pragma once
#include "Enemy.h"
class EXP_ENEMY : public Enemy
{
public:
	EXP_ENEMY(int x, int y, int w, int h, int ELEMENT_ID) : Enemy(x, y, w, h, ELEMENT_ID) {};
	~EXP_ENEMY() {};
};


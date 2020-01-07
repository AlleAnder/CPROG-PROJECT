#pragma once
#include "Sprite.h"

class EnemyEntity : public Sprite
{
public:

	
	virtual ~EnemyEntity() {};

	virtual bool setTarget(Element* target) { this->target = target; return true; };
	void clearTarget() { target = nullptr; };

	void tick();
	virtual void update() {};

	//void shootTarget(int shots);

	
protected:

	EnemyEntity(int x, int y, int w, int h, int ELEMENT_ID, int health, int strength) : Sprite(x, y, w, h, ELEMENT_ID, health, strength) {};
	virtual void moveEnemy();

	Element* target = nullptr;

	int ticks = 0;
};


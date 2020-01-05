#pragma once
#include "Sprite.h"

class EnemyEntity : public Sprite
{
public:

	
	~EnemyEntity() {};

	virtual bool setTarget(Element* target) { this->target = target; return true; };
	void clearTarget() { target = nullptr; };

	void tick();
	virtual void update() {};

	//void shootTarget(int shots);

	
protected:

	EnemyEntity(int x, int y, int w, int h, int ELEMENT_ID) : Sprite(x, y, w, h, ELEMENT_ID) {};
	virtual void moveEnemy();

	Element* target = nullptr;

	int ticks = 0;
};


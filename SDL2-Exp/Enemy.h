#pragma once
#include "Sprite.h"

class Enemy : public Sprite
{
public:

	
	~Enemy() {};

	virtual bool setTarget(Element* target) { this->target = target; return true; };
	void clearTarget() { target = nullptr; };

	void tick();

	//void shootTarget(int shots);

	
protected:

	Enemy(int x, int y, int w, int h, int ELEMENT_ID) : Sprite(x, y, w, h, ELEMENT_ID) {};
	virtual void moveEnemy();

	Element* target = nullptr;
};


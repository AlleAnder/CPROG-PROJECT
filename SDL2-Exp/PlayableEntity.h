#pragma once
#include "Sprite.h"
class PlayableEntity : public Sprite
{
public:

	PlayableEntity(int x, int y, int w, int h, int ELEMENT_ID, int health, int strength) : Sprite(x, y, w, h, ELEMENT_ID, health, strength) {};
	virtual ~PlayableEntity() {};

	virtual Element* shoot() { return nullptr; };

};


#pragma once
#include "Sprite.h"
class PlayableEntity : public Sprite
{
public:

	PlayableEntity(int x, int y, int w, int h, int ELEMENT_ID) : Sprite(x, y, w, h, ELEMENT_ID) {};
	~PlayableEntity() {};

	virtual Element* shoot() { return nullptr; };

};


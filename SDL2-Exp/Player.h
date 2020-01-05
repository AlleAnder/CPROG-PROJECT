#pragma once
#include "PlayableEntity.h"
#include "Asteroid.h"
class Player : public PlayableEntity
{
public:
	Player(int x, int y, int w, int h, int ELEMENT_ID) : PlayableEntity(x, y, w, h, ELEMENT_ID) {};
	~Player() {};

	void keyDown(SDL_Keycode kc);

	void tick();

	Element* shoot();
	bool shoot2;
};


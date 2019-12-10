#pragma once
#include "Sprite.h"
class PlayableEntity : public Sprite
{
public:

	PlayableEntity(int x, int y, int w, int h) : Sprite(x, y, w, h) {};
	~PlayableEntity() {};

	virtual void mouseDown(int x, int y) {};
	virtual void mouseUp(int x, int y) {};

	virtual void keyDown(SDL_Keycode kc) {};
	virtual void keyUp(SDL_Keycode kc) {};


};


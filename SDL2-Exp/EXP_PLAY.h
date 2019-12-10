#pragma once
#include "PlayableEntity.h"
class EXP_PLAY : public PlayableEntity
{
public:
	EXP_PLAY(int x, int y, int w, int h) : PlayableEntity(x, y, w, h) {};
	~EXP_PLAY() {};


	void keyDown(SDL_Keycode kc);
	void keyUp(SDL_Keycode kc);
};


#include "EXP_PLAY.h"

void EXP_PLAY::keyDown(SDL_Keycode kc)
{
	switch (kc) {
	case SDLK_w:
		this->moveFromCurrent(0,-10);
		break;
	case SDLK_a:
		this->moveFromCurrent(-10, 0);
		break;
	case SDLK_s:
		this->moveFromCurrent(0,10);
		break;
	case SDLK_d:
		this->moveFromCurrent(10,0);
		break;
	}
}

void EXP_PLAY::keyUp(SDL_Keycode kc)
{
}

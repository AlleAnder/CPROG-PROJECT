#include "EXP_PLAY.h"

void EXP_PLAY::keyDown(SDL_Keycode kc)
{
	switch (kc) {
	case SDLK_w:
		this->changeVectors(0,-1);
		break;
	case SDLK_a:
		this->changeVectors(-1, 0);
		break;
	case SDLK_s:
		this->changeVectors(0,1);
		break;
	case SDLK_d:
		this->changeVectors(1,0);
		break;
	}
}

void EXP_PLAY::keyUp(SDL_Keycode kc)
{
}

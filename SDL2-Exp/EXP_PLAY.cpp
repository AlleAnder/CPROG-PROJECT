#include "EXP_PLAY.h"

void EXP_PLAY::keyDown(SDL_Keycode kc)
{
	switch (kc) {
	
	case SDLK_w:
		if (vect.vY > -5)
		
		this->changeVectors(0,-2);
		break;
	case SDLK_a:
		if (vect.vX > -5)
			
		this->changeVectors(-2, 0);
		break;
	case SDLK_s:
		if (vect.vY < 5)
		this->changeVectors(0,2);
		break;
	case SDLK_d:
		if (vect.vX < 5)
		this->changeVectors(2,0);
		break;
	case SDLK_SPACE:
		
		this->changeVectors(0, -10);
		
		break;
	}
}


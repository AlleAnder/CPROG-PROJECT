#include "Asteroid.h"

void Asteroid::tick(){
	rotation = vect.dirOTravel();
}

void Asteroid::onColide(){
	Mix_PlayChannel(-1, colSound, 0);
}



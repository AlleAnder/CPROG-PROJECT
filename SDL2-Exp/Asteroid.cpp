#include "Asteroid.h"

void Asteroid::tick(){
	rotation = vect.dirTravel;
}

void Asteroid::onColide(){
	Mix_PlayChannel(-1, colSound, 0);
}



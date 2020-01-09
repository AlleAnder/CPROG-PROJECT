#include "Asteroid.h"

void Asteroid::tick(){
	rotation = vect.dirOTravel();
}

void Asteroid::onColide(Element* e){

}



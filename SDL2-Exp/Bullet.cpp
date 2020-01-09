#include "Bullet.h"

void Bullet::tick() {
	rotation = vect.dirOTravel();

}

void Bullet::onColide(Element* e) {
	Mix_PlayChannel(-1, colSound, 0);
	dead = true;
}



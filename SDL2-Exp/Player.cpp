#include "Player.h"

void Player::keyDown(SDL_Keycode kc)
{
	switch (kc) {

	case SDLK_w:
		if (vect.vY > -5)

			this->changeVectors(0, -1);

		break;
	case SDLK_a:
		if (vect.vX > -5)

			this->changeVectors(-1, 0);

		break;
	case SDLK_s:
		if (vect.vY < 5)
			this->changeVectors(0, 1);

		break;
	case SDLK_d:
		if (vect.vX < 5)
			this->changeVectors(1, 0);

		break;
	case SDLK_SPACE:

		shoot2 = true;


		break;
	}
}

void Player::tick()
{
	rotation = vect.dirTravel;
}

Element* Player::shoot()
{
	if (shoot2) {
		Asteroid* bullet = new Asteroid(rect.x - 10, rect.y - 10, 5, 5, 10);
		bullet->changeVectors(100, 100);
		bullet->setMaxSpeed(10);
		bullet->setColor(255, 255, 255, 255);
		shoot2 = false;
		return bullet;
	}
	else return nullptr;
}



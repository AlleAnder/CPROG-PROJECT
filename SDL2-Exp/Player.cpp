#include "Player.h"

void Player::keyDown(SDL_Keycode kc)
{
	bool moved = false;
	switch (kc) {


	case SDLK_w:
		this->changeVectors(0, -1);
		moved = true;
		texture = boost;
		break;
	case SDLK_a:
		this->changeVectors(-1, 0);
		moved = true;
		texture = boost;
		break;
	case SDLK_s:
		this->changeVectors(0, 1);
		moved = true;
		texture = boost;
		break;
	case SDLK_d:
		this->changeVectors(1, 0);
		moved = true;
		texture = boost;
		break;
	case SDLK_SPACE:
		texture = cruise;
		shoot2 = true;
		break;
	}
}

void Player::keyUp(SDL_Keycode kc)
{
	texture = cruise;
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



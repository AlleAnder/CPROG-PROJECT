#include "Player.h"

void Player::keyDown(SDL_Keycode kc)
{
	bool moved = false;
	switch (kc) {


	case SDLK_w:
		this->changeVectors(0, -0.25);
		moved = true;
		texture = boost;
		break;
	case SDLK_a:
		//rotation-= 7;
		this->changeVectors(-0.25, 0);
		moved = true;
		texture = boost;
		break;
	case SDLK_s:
		this->changeVectors(0, 0.25);
		moved = true;
		texture = boost;
		break;
	case SDLK_d:
		//rotation+= 7;
		this->changeVectors(0.25, 0);
		moved = true;
		texture = boost;
		break;
	case SDLK_SPACE:
		texture = cruise;
		shootable = true;
		break;
	}

	//std::cout << vect.dirTravel << "\n";
}

void Player::moveTDir(int dir){

	
}


void Player::keyUp(SDL_Keycode kc)
{
	texture = cruise;
}

void Player::onColide(Element* e)
{
	health -= 1;
	Mix_PlayChannel(-1, colSound, 0);

	if (health <= 0)
		dead = true;
}



void Player::tick(){
	rotation = vect.dirTravel;
}

Element* Player::shoot()
{
	if (shootable) {
		Asteroid* bullet = new Asteroid(rect.x - 10, rect.y - 10, 5, 5);
		bullet->changeVectors(100, 100);
		bullet->setMaxSpeed(5);
		bullet->setColor(255, 255, 255, 255);
		bullet->setCollidable(true);
		shootable = false;
		return bullet;
	}
	else return nullptr;
}





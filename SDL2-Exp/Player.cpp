#include "Player.h"

Player::Player(int x, int y, int w, int h, int health, int strength, Mix_Chunk* col) : PlayableEntity(x, y, w, h, 1, health, strength), colSound(col)
{
	calculateShotSpawnDistance();
}

void Player::keyDown(SDL_Keycode kc)
{
	bool moved = false;
	switch (kc) {


	case SDLK_w:
		this->changeVectors(0, -0.5);
		moved = true;
		texture = boost;
		break;
	case SDLK_a:
		//rotation-= 7;
		this->changeVectors(-0.5, 0);
		moved = true;
		texture = boost;
		break;
	case SDLK_s:
		this->changeVectors(0, 0.5);
		moved = true;
		texture = boost;
		break;
	case SDLK_d:
		//rotation+= 7;
		this->changeVectors(0.5, 0);
		moved = true;
		texture = boost;
		break;
	}

	//std::cout << vect.dirTravel << "\n";
}

void Player::moveTDir(int dir){

	
}

void Player::calculateShotSpawnDistance(){
	if (rect.w >= rect.h)
		shotSpawnDistance = rect.w / 2 + 10;
	else
		shotSpawnDistance = rect.h / 2 + 10;
}


void Player::keyUp(SDL_Keycode kc)
{
	texture = cruise;

	switch (kc) {
	case SDLK_SPACE:
		shootable = true;
		Mix_PlayChannel(-1, shotSound, 0);
		break;
	}
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

		SDL_Point* dirVec = vect.getDirVectors(vect.dirTravel, shotSpawnDistance);
		Asteroid* bullet = new Asteroid((rect.x + rect.w / 2) + dirVec->x, (rect.y + rect.h / 2) + dirVec->y, 5, 5);
		bullet->setMaxSpeed(20);
		bullet->changeVectors(dirVec->x * 1000.0, dirVec->y * 1000.0);
		delete dirVec;

		bullet->setColSound(shotColSound);
		bullet->setColor(255, 255, 255, 255);
		bullet->setCollidable(true);
		shootable = false;
		return bullet;
	}
	else return nullptr;
}





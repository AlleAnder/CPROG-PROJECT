#include "Player.h"

Player::Player(int x, int y, int w, int h, int health, int strength, Mix_Chunk* col) : PlayableEntity(x, y, w, h, 1, health, strength), colSound(col)
{
	calculateShotSpawnDistance();
}

void Player::keyDown(SDL_Keycode kc)
{
	SDL_Point* dirVec = vect.getDirVectors(rotation, 1000);
	bool moved = false;
	switch (kc) {


	case SDLK_w:
		
		this->changeVectors(dirVec->x/1000.0, dirVec->y / 1000.0);
		moved = true;
		texture = boost;
		break;
	case SDLK_a:
		rotation-= 10;
		//this->changeVectors(-0.5, 0);
		moved = true;
		//texture = boost;
		break;
	case SDLK_s:
		this->changeVectors(-dirVec->x / 1000.0, -dirVec->y / 1000.0);
		moved = true;
		texture = boost;
		break;
	case SDLK_d:
		rotation+= 10;
		//this->changeVectors(0.5, 0);
		moved = true;
	//	texture = boost;
		break;
	}

	delete dirVec;
	//std::cout << vect.dirTravel << "\n";
}

void Player::moveTDir(int dir){

	
}

void Player::calculateShotSpawnDistance(){
	if (rect.w >= rect.h)
		shotSpawnDistance = rect.w / 2;
	else
		shotSpawnDistance = rect.h / 2;
}


void Player::keyUp(SDL_Keycode kc)
{
	texture = cruise;

	switch (kc) {
	case SDLK_SPACE:
		shooting = true;
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
//	rotation = vect.dirOTravel();
}

Element* Player::shoot()
{
	if (shooting) {

		SDL_Point* dirVec = vect.getDirVectors(rotation, shotSpawnDistance);
		Bullet* bullet = new Bullet((rect.x + rect.w / 2) + dirVec->x - 10, (rect.y + rect.h / 2) + dirVec->y - 10, 10, 20);
		bullet->setMaxSpeed(20);
		bullet->changeVectors(dirVec->x , dirVec->y);
		delete dirVec;

		bullet->setTexture(laser);
		bullet->setColSound(shotColSound);
		bullet->setColor(255, 0, 255, 255);
		bullet->setCollidable(true);
		shooting = false;
		return bullet;
	}
	else return nullptr;
}





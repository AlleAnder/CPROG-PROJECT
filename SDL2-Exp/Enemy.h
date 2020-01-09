#pragma once
#include "EnemyEntity.h"
#include <SDL_mixer.h>
class Enemy : public EnemyEntity
{
public:
	Enemy(int x, int y, int w, int h, int health, int strength, Mix_Chunk* col) : EnemyEntity(x, y, w, h, ELEMENT_ID, health, strength), collision(col){};

	void update();
	void onColide(Element* colWith);
	void setDeathSound(Mix_Chunk* death) { this->death = death; };

private:

	Mix_Chunk* death;
	Mix_Chunk* collision;
};





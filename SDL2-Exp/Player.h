#pragma once
#include "PlayableEntity.h"
#include "Asteroid.h"
#include "Texture.h"
#include <SDL_mixer.h>

class Player : public PlayableEntity
{
public:
	Player(int x, int y, int w, int h, int health, int strength, Mix_Chunk* col) : PlayableEntity(x, y, w, h, 1, health, strength), colSound(col){};
	~Player() {};

	void keyDown(SDL_Keycode kc);
	void keyUp(SDL_Keycode kc);

	void onColide(Element* e);

	void tick();

	Element* shoot();
	bool shootable = false;

	void setMovingTexture(SDL_Texture* texture) { boost = texture; };
	void setCruiseTexture(SDL_Texture* texture) { cruise = texture; this->texture = cruise; };

	int getHealth() { return health; };

private:
	void moveTDir(int dir);

	Mix_Chunk* colSound;
	SDL_Texture* boost = nullptr;
	SDL_Texture* cruise = nullptr;
};

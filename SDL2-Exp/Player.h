#pragma once
#include "PlayableEntity.h"
#include "Asteroid.h"
#include "Texture.h"

class Player : public PlayableEntity
{
public:
	Player(int x, int y, int w, int h, int ELEMENT_ID) : PlayableEntity(x, y, w, h, ELEMENT_ID) {};
	~Player() {};

	void keyDown(SDL_Keycode kc);
	void keyUp(SDL_Keycode kc);

	void tick();

	Element* shoot();
	bool shoot2;

	void setMovingTexture(SDL_Texture* texture) { boost = texture; };
	void setCruiseTexture(SDL_Texture* texture) { cruise = texture; this->texture = cruise; };

private:

	SDL_Texture* boost;
	SDL_Texture* cruise;
};


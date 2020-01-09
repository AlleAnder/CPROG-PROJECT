#pragma once
#include "Sprite.h"
#include <SDL_mixer.h>

class PlayableEntity : public Sprite
{
public:

	virtual ~PlayableEntity() {};
	virtual Element* shoot() { return nullptr; };

protected:

	PlayableEntity(int x, int y, int w, int h, int ELEMENT_ID, int health, int strength) : Sprite(x, y, w, h, ELEMENT_ID, health, strength) {};

private :
	

	PlayableEntity(const PlayableEntity& c) = delete;
	const PlayableEntity& operator= (const PlayableEntity& c) = delete;
};


#pragma once
#include "Sprite.h"
#include <SDL_mixer.h>

class PlayableEntity : public Sprite
{
public:

	PlayableEntity(int x, int y, int w, int h, int ELEMENT_ID, int health, int strength) : Sprite(x, y, w, h, ELEMENT_ID, health, strength) {};
	virtual ~PlayableEntity() {};

	virtual Element* shoot() { return nullptr; };

	void setShotSound(Mix_Chunk* shot) { shotSound = shot; };
	void setShotColSound(Mix_Chunk* shotCol) { shotColSound = shotCol; };

protected:

	Mix_Chunk* shotSound = nullptr;
	Mix_Chunk* shotColSound = nullptr;

};


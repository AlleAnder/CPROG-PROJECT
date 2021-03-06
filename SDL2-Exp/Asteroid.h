#pragma once
#include "Element.h"
#include <SDL_mixer.h>

class Asteroid : public Element
{
public:
	Asteroid(int x, int y, int w, int h) : Element(x, y, w, h, 3) {};

	void tick();
	void onColide(Element* e);
	void setColSound(Mix_Chunk* sound) { colSound = sound; };

private:
	Mix_Chunk* colSound = nullptr;

	
};
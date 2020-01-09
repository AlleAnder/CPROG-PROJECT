#pragma once
#include <SDL_mixer.h>
#include "Element.h"

class Bullet : public Element
{
public:
	Bullet(int x, int y, int w, int h) : Element(x, y, w, h, 4) {};

	void tick();
	void onColide(Element* e);
	void setColSound(Mix_Chunk* sound) { colSound = sound; };

private:

	Mix_Chunk* colSound = nullptr;
};


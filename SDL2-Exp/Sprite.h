#pragma once
#include <SDL.h>
#include "DynamicElement.h"
class Sprite : public Element
{
public:
	SDL_Rect* getRect() {}; //For collision detection
	

protected:

	Sprite(int x, int y, int w, int h) : Element(x, y, w, h) {};
	~Sprite() {};

private:

	Sprite(const Sprite& c) = delete;
	const Sprite& operator= (const Sprite& c) = delete;

};


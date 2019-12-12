#pragma once
#include <SDL.h>
#include "DynamicElement.h"
#include "Vector.h"

class EntityManager;

class Sprite : public Element
{
public:
	SDL_Rect* getRect() {}; //For collision detection
	
	bool(EntityManager::*collideFunc)(SDL_Rect* rect, Vector* vec);
	void setCollideCheck(bool(EntityManager::* collideFunc)(SDL_Rect* rect, Vector* vec));

	
	void moveFromCurrent(int x, int y);

protected:

	Sprite(int x, int y, int w, int h, int ELEMENT_ID) : Element(x, y, w, h, ELEMENT_ID) {};
	~Sprite() {};

private:

	Sprite(const Sprite& c) = delete;
	const Sprite& operator= (const Sprite& c) = delete;

};


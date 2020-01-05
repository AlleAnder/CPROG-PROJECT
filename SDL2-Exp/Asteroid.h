#pragma once
#include "Element.h"
class Asteroid : public Element
{
public:
	Asteroid(int x, int y, int w, int h) : Element(x, y, w, h, 3) {};
	~Asteroid() {};

	void tick();


private:

};
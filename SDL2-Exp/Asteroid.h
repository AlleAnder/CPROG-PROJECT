#pragma once
#include "Element.h"
class Asteroid : public Element
{
public:
	Asteroid(int x, int y, int w, int h, int ELEMENT_ID) : Element(x, y, w, h, ELEMENT_ID) {};
	~Asteroid();


private:

};
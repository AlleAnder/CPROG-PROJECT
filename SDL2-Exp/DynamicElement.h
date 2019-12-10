#pragma once
#include "Element.h"

class DynamicElement : public Element
{
public:

	DynamicElement(int x, int y, int w, int h) : Element(x, y, w, h) {};
	~DynamicElement() {};

	virtual void mouseDown(int x, int y) {};
	virtual void mouseUp(int x, int y) {};

	virtual void keyDown(SDL_Keycode kc) {};
	virtual void keyUp(SDL_Keycode kc) {};

	

};


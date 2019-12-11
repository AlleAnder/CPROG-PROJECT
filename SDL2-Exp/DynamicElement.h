#pragma once
#include "Element.h"

class DynamicElement : public Element
{
public:

	DynamicElement(int x, int y, int w, int h, int ELEMENT_ID) : Element(x, y, w, h, ELEMENT_ID) {};
	~DynamicElement() {};

	virtual void mouseDown(Uint8 e) {};
	virtual void mouseUp(Uint8 e) {};

	virtual void keyDown(SDL_Keycode kc) {};
	virtual void keyUp(SDL_Keycode kc) {};

	

};


#pragma once
#include <iostream>
#include "SDL.h"
#include "SDL_image.h"

class Element
{
public:

	virtual void draw(SDL_Renderer* ren);

	virtual void moveToNew(int x, int y);
	virtual void moveFromCurrent(int x, int y);
	void setTexture(SDL_Texture* texture);
	void setColor(int r, int g, int b, int a);
	void setColidable(bool colidable) { this->colidable = colidable; };
	SDL_Rect* getRect();

	~Element() {};

	const int ELEMENT_ID;
	bool colidable = false;

	virtual void mouseDown(Uint8 e) {};
	virtual void mouseUp(Uint8 e) {};

	virtual void keyDown(SDL_Keycode kc) {};
	virtual void keyUp(SDL_Keycode kc) {};

protected:

	Element(int x, int y, int w, int h, int ELEMENT_ID);
	
	SDL_Texture* texture;
	SDL_Rect rect;
	int r = 0, g = 0, b = 0, a = 255;
	

private:

	Element(const Element& c) = delete;
	const Element& operator= (const Element& c) = delete;

};


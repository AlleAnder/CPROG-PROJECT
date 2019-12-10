#pragma once
#include <iostream>
#include "SDL.h"
#include "SDL_image.h"

class Element
{
public:

	virtual void draw(SDL_Renderer* ren);

	void moveToNew(int x, int y);
	void moveFromCurrent(int x, int y);
	void setImage(SDL_Renderer* ren, const char* path);
	void setColor(int r, int g, int b, int a);

	~Element() {
		SDL_DestroyTexture(texture);
	};

protected:

	Element(int x, int y, int w, int h);
	
	
	SDL_Texture* texture;
	SDL_Rect rect;
	int r = 0, g = 0, b = 0, a = 255;

private:

	Element(const Element& c) = delete;
	const Element& operator= (const Element& c) = delete;

};


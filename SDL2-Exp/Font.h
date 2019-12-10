#pragma once
#include <SDL_ttf.h>
class Font
{
	Font(const char* path, int size);
	~Font();

	void setFont(const char* path, int size);
	TTF_Font* getFont();

	TTF_Font* font;

};


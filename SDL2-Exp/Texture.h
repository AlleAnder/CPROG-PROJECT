#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
class Texture
{
public:

	Texture(SDL_Renderer* ren, const char* path);
	~Texture();

	void replaceTexture(SDL_Renderer* ren, const char* path);

	SDL_Texture* getTexture();

	void setTransparentColor(int r, int g, int b);

private:

	SDL_Texture* texture;
	SDL_PixelFormat* surfFormat;
};
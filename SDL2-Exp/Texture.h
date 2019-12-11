#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
class Texture
{
	SDL_Texture* texture;

public:

	Texture(SDL_Renderer* ren, const char* path);
	~Texture();

	void replaceTexture(SDL_Renderer* ren, const char* path);

	SDL_Texture* getTexture();

};
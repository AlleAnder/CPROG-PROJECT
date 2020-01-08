#include "Texture.h"

Texture::Texture(SDL_Renderer* ren, const char* path) {
	replaceTexture(ren, path);
}

Texture::~Texture() {
	SDL_DestroyTexture(texture);
	
}

void Texture::replaceTexture(SDL_Renderer* ren, const char* path) {
	SDL_Surface* surf = IMG_Load(path);
	if (surf == NULL)
		std::cout << "Could not load image!";
	else {
		this->texture = SDL_CreateTextureFromSurface(ren, surf);
		surfFormat = surf->format;
		SDL_FreeSurface(surf);
		if (texture == NULL)
			std::cout << "Could not create texture from image!";
	}
}



SDL_Texture* Texture::getTexture() {
	return texture;
}

void Texture::setTransparentColor(int r, int g, int b)
{
	if (r > 255)
		r = 255;
	else if (r < 0)
		r = 0;

	if (g > 255)
		g = 255;
	else if (g < 0)
		g = 0;

	if (b > 255)
		b = 255;
	else if (b < 0)
		b = 0;

	Uint32 color = SDL_MapRGB(surfFormat, r, g, b);
	
}

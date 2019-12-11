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
		SDL_FreeSurface(surf);
		if (texture == NULL)
			std::cout << "Could not create texture from image!";
	}
}

SDL_Texture* Texture::getTexture() {
	return texture;
}
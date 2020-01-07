#include "Sprite.h"

Sprite::Sprite(int x, int y, int w, int h, int ELEMENT_ID, int health, int strength) : Element(x, y, w, h, ELEMENT_ID),
lifeTot({ x, y - 30, w, 10 }), startingHealth(health), health(health)
{
	this->strength = strength;
	lifeLost = { x, y - 30, 0, 10 };

};
void Sprite::rndStats(int min, int max){
	health = rand() % (max - min) + min;
	strength = rand() % (max - min) + min;
}


void Sprite::draw(SDL_Renderer* ren) {
	if (texture == NULL) {
		SDL_SetRenderDrawColor(ren, r, g, b, a);
		SDL_RenderFillRect(ren, &rect);
		SDL_RenderDrawRect(ren, &rect);
	}
	else
		SDL_RenderCopyEx(ren, texture, NULL, &rect, rotation, NULL, SDL_FLIP_NONE);

	if (showHealth) {
		updateHealthBar();
		drawHealthBar(ren);
	}
}

void Sprite::updateHealthBar(){
	lifeLost.x = rect.x;
	lifeLost.y = rect.y - 30;
	lifeTot.x = rect.x;
	lifeTot.y = rect.y - 30;

	lifeLost.w = ((lifeTot.w / (startingHealth* 1.0)) * health);
}

void Sprite::drawHealthBar(SDL_Renderer* ren){
	//Draw totalLife
	SDL_SetRenderDrawColor(ren, 255, 0, 0, 255);
	SDL_RenderFillRect(ren, &lifeTot);
	SDL_RenderDrawRect(ren, &lifeTot);

	//Draw lostLife
	SDL_SetRenderDrawColor(ren, 0, 255, 0, 255);
	SDL_RenderFillRect(ren, &lifeLost);
	SDL_RenderDrawRect(ren, &lifeLost);
}

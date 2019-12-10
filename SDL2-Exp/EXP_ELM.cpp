#include "EXP_ELM.h"
#include <iostream>

EXP_ELM::~EXP_ELM(){

}

void EXP_ELM::draw(SDL_Renderer* ren){
	SDL_SetRenderDrawColor(ren, r, g, b, a);
	SDL_RenderFillRect(ren, &rect);
	SDL_RenderDrawRect(ren, &rect);
	}


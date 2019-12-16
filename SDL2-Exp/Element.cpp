#include "Element.h"


Element::Element(int x, int y, int w, int h, int ELEMENT_ID) : ELEMENT_ID(ELEMENT_ID) {
	SDL_Rect rect = { x, y, w, h };
	this->rect = rect;
	this->movedRect = rect;

}



Element::~Element() {
	vect.~Vector();
}

void Element::tick() {
	changeVectors(0,0);
}

void Element::draw(SDL_Renderer* ren) {
	if (texture == NULL) {
		SDL_SetRenderDrawColor(ren, r, g, b, a);
		SDL_RenderFillRect(ren, &rect);
		SDL_RenderDrawRect(ren, &rect);
	}
	else
		SDL_RenderCopy(ren, texture, NULL, &rect);
}

void Element::setColor(int r, int g, int b, int a) {
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}

void Element::setElasticity(double elasticity){
	if (elasticity > 100)
		this->elasticity = 2;
	else if (elasticity < 0) 
		this->elasticity = 1;
	else {
		this->elasticity += elasticity / 100;

	}
}

void Element::changeVectors(double x, double y){
	vect.changeVect(x,y);
	moveFromCurrent(vect.vX, vect.vY);
}

void Element::moveFromCurrent(int x, int y) {
	if (vect.maxSpeed > 0) {
		this->movedRect.x = this->rect.x + x;
		this->movedRect.y = this->rect.y + y;
	}
}

void Element::moveToNew(int x, int y) {
	this->rect.x = x;
	this->rect.y = y;
}
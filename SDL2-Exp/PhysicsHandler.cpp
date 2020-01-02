#include "PhysicsHandler.h"

PhysicsHandler::PhysicsHandler(double gravity, int screenX, int screenY){
	this->gravity = gravity;
	this->screenX = screenX;
	this->screenY = screenY;
}

bool PhysicsHandler::elementsCollide(Element* e, Element* e2){
	if (e != e2) {
		int colDir = rectsCollide(e->getMovedRect(), e2->getRect());

		if (colDir != 0) {
			e->onColide(e2);
		}

		if (colDir == 1) {
			e->resetMovedRect();
			e2->changeVectors(e->getXVector() / e2->getElasticity(), e->getYVector() * 0.5);
			e->changeVectors(0 - e->getXVector() * e2->getElasticity(), 0 - e->getYVector() * 0.5);
			return true;

		}
		else if (colDir == 2) {
			e->resetMovedRect();
			e2->changeVectors(e->getXVector() * 0.5, e->getYVector() / e2->getElasticity());
			e->changeVectors(0 - e->getXVector() * 0.5, 0 - e->getYVector() * e2->getElasticity());
			return true;
		}
	}
	return false;
}

bool PhysicsHandler::windowElementCollide(Element* e){
	int colDir = windowCollide(e->getMovedRect());

	if (colDir == 1) {
		e->resetMovedRect();
		e->changeVectors(0 - e->getXVector() * 1.5, 0 - e->getYVector() * 0.1);
		return true;
	}
	else if (colDir == 2) {
		e->resetMovedRect();
		e->changeVectors(0 - e->getXVector() * 0.1, 0 - e->getYVector() * 1.5);
		return true;
	}
	return false;
}

void PhysicsHandler::applyGravityVector(Element* e){
	e->changeVectors(0, gravity/30);
}

int PhysicsHandler::rectsCollide(const SDL_Rect* r1, const SDL_Rect* r2){
	if (r1->x + r1->w >= r2->x &&
		r2->x + r2->w >= r1->x &&
		r1->y + r1->h >= r2->y &&
		r2->y + r2->h >= r1->y)
		if ((r1->x + r1->w <= r2->x || r2->x + r2->w <= r1->x) && 
			(r1->y + r1->h >= r2->y || r2->y + r2->h >= r1->y))
			return 1;
		else
			return 2;
	return 0;
}

int PhysicsHandler::windowCollide(const SDL_Rect* r1){
	if (r1->x + r1->w > screenX || r1->x < 0)
		return 1;
	else if (r1->y + r1->h > screenY || r1->y < 0)
		return 2;
	return 0;
}

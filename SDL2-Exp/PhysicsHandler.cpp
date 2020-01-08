#include "PhysicsHandler.h"

PhysicsHandler::PhysicsHandler(double gravity, int screenX, int screenY) : screenX(screenX) , screenY(screenY){
	gravity = gravity;
}

bool PhysicsHandler::elementsCollide(Element* e, Element* e2){
	if (e != e2) {
		int colDir = rectsCollide(e->getMovedRect(), e2->getMovedRect());
		
		if (colDir != 0) 
			e->onColide(e2);
		
		if (colDir == 1) { //col from side
			e->resetMovedRect();
			e2->changeVectors(e->getXVector() / e2->getElasticity(), e->getYVector() * 0.5);
			e->changeVectors(0 - e->getXVector() * e2->getElasticity(), 0 - e->getYVector() * 0.5);
			return true;
		}
		else if (colDir == 2) { // col from top
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
	if (r1->x + r1->w - offset >= r2->x + offset - 5 && r1->x + offset <= r2->x + r2->w - offset + 5) // within x, 5 is buffer
		if (r1->y + r1->h - offset >= r2->y + offset && r1->y + offset <= r2->y + r2->h - offset)
			return 1; //side
	if (r1->y + r1->h - offset >= r2->y + offset - 5 && r1->y + offset <= r2->y + r2->h - offset + 5) // within y, 5 is buffer
		if (r1->x + r1->w - offset >= r2->x + offset && r1->x + offset < r2->x + r2->w - offset)
			return 2; //top
	return 0;
}

int PhysicsHandler::windowCollide(const SDL_Rect* r1){
	if (r1->x + r1->w > screenX || r1->x < 0)
		return 1;
	else if (r1->y + r1->h > screenY || r1->y < 0)
		return 2;
	return 0;
}

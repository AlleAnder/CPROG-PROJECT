#pragma once
#include "Element.h"

class PhysicsHandler
{
public:
	PhysicsHandler(double gravity, int screenX, int screenY);
	~PhysicsHandler() {};

	void setGravity(double gravity) { this->gravity = gravity; };
	void setAirResistance(double resistance) { airResistance = resistance; };

	bool elementsCollide(Element* e, Element* e2);
	bool windowElementCollide(Element* e);
	void applyGravityVector(Element* e);

private:

	double gravity, airResistance = 0;
	int screenX, screenY;

	int rectsCollide(const SDL_Rect* r1, const SDL_Rect* r2);
	int windowCollide(const SDL_Rect* r1);
};


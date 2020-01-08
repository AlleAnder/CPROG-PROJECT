#pragma once
#include "Element.h"

class PhysicsHandler
{
public:
	PhysicsHandler(double gravity, int screenX, int screenY);
	~PhysicsHandler() {};

	void setGravity(double gravity) { this->gravity = gravity; };
	void setHitboxOffset(int px) { offset = px * -1; };

	bool elementsCollide(Element* e, Element* e2);
	bool windowElementCollide(Element* e);
	void applyGravityVector(Element* e);

	const int screenX, screenY;

private:

	double gravity = 0;
	int offset = 0;

	int rectsCollide(const SDL_Rect* r1, const SDL_Rect* r2);
	int windowCollide(const SDL_Rect* r1);
};


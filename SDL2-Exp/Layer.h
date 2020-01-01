#pragma once
#include "Element.h"
#include <vector>
#include "PlayableEntity.h"

struct Layer
{
public:
	Layer(PlayableEntity* player);
	~Layer();

	void addElement(Element* elm);
	void removeElement(Element* elm);

	virtual void moveLayer(int x, int y);
	void setMovedLayer();
	void setMovementSpeedToPlayer(int percentage);
	double getMovementSpeed() { return movementSpeed; };

	virtual void drawLayer(SDL_Renderer* ren);
	virtual void tickLayer() {};

	void setColidable(bool col);

	std::vector<Element*> elements;

	bool isCollidable() { return collidable; };

protected:

	double movementSpeed = 1;
	PlayableEntity* player;

private:

	bool collidable = false; //This can cause problems when other elements collide with layer, player stops as well, everything freezes
};


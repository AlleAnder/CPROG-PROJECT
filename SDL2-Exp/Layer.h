#pragma once
#include "Element.h"
#include <vector>
#include "PlayableEntity.h"

struct Layer
{
public:
	Layer(PlayableEntity* player);
	virtual ~Layer();

	void addElement(Element* elm);
	void removeElement(Element* elm);

	virtual void moveLayer(int x, int y);
	void setMovedLayer();
	void setElasticity(int el);
	void setMovementSpeedToPlayer(int percentage);
	double getMovementSpeed() { return movementSpeed; };

	virtual void drawLayer(SDL_Renderer* ren);
	virtual void tickLayer() {};

	void setCollidable(bool col);

	std::vector<Element*>* getElements() { return &elements; };

	bool isCollidable() { return collidable; };

protected:
	std::vector<Element*> elements;
	double movementSpeed = 1;
	PlayableEntity* player;

private:

	bool collidable = false;
};


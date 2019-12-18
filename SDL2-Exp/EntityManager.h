#pragma once
#include <vector>
#include "Element.h"
#include "PlayableEntity.h"
#include "Vector.h"
#include <iostream>
#include "PhysicsHandler.h"

class EntityManager
{
public:
	void setPlayer(PlayableEntity* player);
	void addElement(Element* elm);
	void removeElement(const Element* elm);
	std::vector<Element*> getEntities();
	void triggerEvent(const SDL_Event event);
	void updateElements(SDL_Renderer* ren);

	EntityManager(PhysicsHandler* physics);
	~EntityManager();

private:
	int screenX = 1000;
	int screenY = 700;

	PlayableEntity* player = NULL;
	std::vector<Element*> elements;
	PhysicsHandler* physics;

};


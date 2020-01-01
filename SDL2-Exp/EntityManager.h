#pragma once
#include <vector>
#include "Element.h"
#include "PlayableEntity.h"
#include "Vector.h"
#include <iostream>
#include "PhysicsHandler.h"
#include "Layer.h"

class EntityManager
{
public:
	void setPlayer(PlayableEntity* player);
	void addElement(Element* elm);
	void addLayer(Layer* layer);

	void removeElement(const Element* elm);
	void removeLayer(Layer* layer);

	std::vector<Element*> getEntities();
	void triggerEvent(const SDL_Event event);
	void updateElements(SDL_Renderer* ren);
	void setPhysics(PhysicsHandler* physics) { this->physics = physics; };

	EntityManager(PhysicsHandler* physics);
	~EntityManager();

private:
	int screenX = 1000;
	int screenY = 700;

	PlayableEntity* player = NULL;
	std::vector<Element*> elements;
	std::vector<Layer*> layers;

	PhysicsHandler* physics;

	bool outOfBounds(Element* e);


};


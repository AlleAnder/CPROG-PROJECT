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
	void addForeLayer(Layer* layer);
	void addBackLayer(Layer* layer);

	void setScrolling(bool scrolling) { scrollingMap = scrolling; };

	void removeElement(const Element* elm);
	void removeLayer(Layer* layer);

	std::vector<Element*> getEntities();
	void triggerEvent(const SDL_Event event);
	void updateElements(SDL_Renderer* ren);
	void setPhysics(PhysicsHandler* physics) { this->physics = physics; };
	void setHitboxOffset(int px) { physics->setHitboxOffset(px); };

	EntityManager(PhysicsHandler* physics);
	~EntityManager();

private:
	int screenX;
	int screenY;

	PlayableEntity* player = NULL;
	std::vector<Element*> elements;
	std::vector<Layer*> bLayer, fLayer;
	PhysicsHandler* physics;

	bool outOfBounds(Element* e);
	bool scrollingMap = false;

};


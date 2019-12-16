#pragma once
#include <vector>
#include "Element.h"
#include "PlayableEntity.h"
#include "Vector.h"
#include <iostream>

class EntityManager
{
public:
	void setPlayer(PlayableEntity* player);
	void addElement(Element* elm);
	void removeElement(const Element* elm);
	std::vector<Element*> getEntities();
	void triggerEvent(const SDL_Event event);
	void updateElements(SDL_Renderer* ren);
	

	EntityManager();
	~EntityManager();

private:
	int screenX = 1000;
	int screenY = 700;

	PlayableEntity* player;
	std::vector<Element*> elements;

	int rectsCollide(const SDL_Rect* r1, const SDL_Rect* r2);
	int windowCollide(const SDL_Rect* r1);
	
};


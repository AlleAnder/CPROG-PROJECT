#pragma once
#include <vector>
#include "Element.h"
#include "PlayableEntity.h"

class EntityManager
{
public:
	void setPlayer(PlayableEntity* player);
	void addElement(Element* elm);
	void removeElement(Element* elm);
	std::vector<Element*> getEntities();
	void triggerEvent(SDL_Event event);
	void updateElements();

	EntityManager();
	~EntityManager();

private:
	PlayableEntity* player = NULL;
	std::vector<Element*> elements;

	bool rectsCollide(SDL_Rect* r1, SDL_Rect* r2);
};


#include "EntityManager.h"

EntityManager::~EntityManager() {
	physics->~PhysicsHandler();
	elements.clear();
}

EntityManager::EntityManager(PhysicsHandler* physics) {
	this->physics = physics;

}

void EntityManager::setPlayer( PlayableEntity* player) {
	this->player = player;
elements.push_back(player);
}

void EntityManager::addElement( Element* elm) {
	elements.push_back(elm);

}

void EntityManager::removeElement(const Element* comp) {
	for (int i = 0; i < elements.size() / sizeof(Element); i++) {
		if (elements.at(i) == comp) {
			elements.erase(elements.begin() + i);
		}
	}
}

std::vector<Element*> EntityManager::getEntities() {
	return elements;
}

void EntityManager::triggerEvent(SDL_Event event) {
	switch (event.type) {
	case SDL_KEYDOWN:
		for (int i = 0; i < elements.size(); i++) {
			elements.at(i)->keyDown(event.key.keysym.sym);
			
		}
		break;
	case SDL_KEYUP:
		for (Element* e : elements) 
			e->keyUp(event.key.keysym.sym);
		break;
	case SDL_MOUSEBUTTONDOWN:
		for (Element* e : elements) 
			e->mouseDown(event.button.button);
		break;
	case SDL_MOUSEBUTTONUP:
		for (Element* e : elements)
			e->mouseUp(event.button.button);
		break;
	}
}

void EntityManager::updateElements(SDL_Renderer* ren) {
	for (Element* e : elements) {
		bool colFound = false;
		physics->applyGravityVector(e);

		if (e->collidable) {
			if (physics->windowElementCollide(e))
				colFound = true;

			for (Element* e2 : elements) {
				if (colFound)	
					break;
				if (physics->elementsCollide(e, e2))
					colFound = true;

			}
		}

		
		if(!colFound)
			e->setMovedRect();
		e->draw(ren);
		e->tick();
		
	}
}


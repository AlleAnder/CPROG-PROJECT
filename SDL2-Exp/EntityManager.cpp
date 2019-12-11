#include "EntityManager.h"

EntityManager::~EntityManager() {
	elements.clear();
}

void EntityManager::setPlayer(PlayableEntity* player) {
	this->player = player;
	elements.push_back(player);
}

void EntityManager::addElement(Element* elm) {
	elements.push_back(elm);

}

void EntityManager::removeElement(Element* comp) {
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
			std::cout << "col\n";
			if (elements.at(i)->colidable)
			for (int ii = 0; ii < elements.size(); ii++) {
				
						if (!rectsCollide(elements.at(i)->getRect(), elements.at(ii)->getRect()) && i != ii) {
							std::cout << rectsCollide(elements.at(i)->getRect(), elements.at(ii)->getRect());
							elements.at(i)->keyDown(event.key.keysym.sym);
						}
			}
			else
				elements.at(i)->keyDown(event.key.keysym.sym);
		}/*
		for (Element* e : elements)
			if (e->colidable) {
				for (Element* e1 : elements)
					if (!rectsCollide(e->getRect(), e1->getRect()) && e != e1) {
						std::cout << "col\n";
						e->keyDown(event.key.keysym.sym);
					}
			}
			else
				e->keyDown(event.key.keysym.sym);*/
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

bool EntityManager::rectsCollide(SDL_Rect* r1, SDL_Rect* r2) {
	if(r1->x + r1->w >= r2->x &&
		r2->x + r2->w >= r1->x &&
		r1->y + r1->h >= r2->y &&
		r2->y + r2->h >= r1->y)
	return true;
	return false;
}

void EntityManager::updateElements() {

}

EntityManager::EntityManager() {

}
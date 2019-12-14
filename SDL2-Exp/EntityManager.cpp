#include "EntityManager.h"

EntityManager::~EntityManager() {
	elements.clear();
}

void EntityManager::setPlayer( PlayableEntity* player) {
	players.push_back(player);
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

int EntityManager::rectsCollide(const SDL_Rect* r1, const SDL_Rect* r2) {
	if (r1->x + r1->w >= r2->x &&
		r2->x + r2->w >= r1->x &&
		r1->y + r1->h >= r2->y &&
		r2->y + r2->h >= r1->y)
			return 1;
		/*Find out how to find out what surface colided w what
		and return 1 or 2 depending*/
	return false;
}

void EntityManager::updateElements(SDL_Renderer* ren) {
	for (Element* e : elements) {
		if (e->collidable) {
			e->changeVectors(0, 1);
			for (int ii = 0; ii < elements.size(); ii++) {

				int colDir = rectsCollide(e->getRect(), elements.at(ii)->getRect()) && e != elements.at(ii);
				if (colDir) {
					e->changeVectors(0 - e->getXVector() * 1.85, 0 - e->getYVector() * 1.85);
					std::cout << "COLLISIO\n" << colDir;
				}
				else if (colDir == 2) {
					e->changeVectors(0 - e->getXVector() * 1.85, 0 - e->getYVector() * 1.85);
					std::cout << "COLLISION\n" << colDir;
				}
				else {
					std::cout << "NO COLLISION\n" << colDir;
					e->setMovedRect();
				}
			}
		}
		else
			e->setMovedRect();

		e->tick();
		e->draw(ren);
	}

}

EntityManager::EntityManager() {

}
#include "EntityManager.h"

EntityManager::~EntityManager() {
	elements.clear();
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

int EntityManager::rectsCollide(const SDL_Rect* r1, const SDL_Rect* r2) {
	if (r1->x + r1->w >= r2->x &&
		r2->x + r2->w >= r1->x &&
		r1->y + r1->h >= r2->y &&
		r2->y + r2->h >= r1->y)
		if ((r1->x + r1->w <= r2->x || r2->x + r2->w <= r1->x) && (r1->y + r1->h >= r2->y || r2->y + r2->h >= r1->y))
			return 1;
		else
			return 2;
	
	return 0;
}

int EntityManager::windowCollide(const SDL_Rect* r1){
	if (r1->x + r1->w > screenX || r1->x < 0)
		return 1;
	else if (r1->y + r1->h > screenY || r1->y < 0)
		return 2;
	return 0;
}
 

void EntityManager::updateElements(SDL_Renderer* ren) {
	for (Element* e : elements) {
		bool colFound = false;
		e->changeVectors(0, 0.32);

		if (e->collidable) {

			if (windowCollide(e->getMovedRect()) == 1) {
					e->resetMovedRect();
				e->changeVectors(0 - e->getXVector() * 1.5, 0 - e->getYVector() * 0.1);
				colFound = true;
			}
			else if (windowCollide(e->getMovedRect()) == 2) {
				e->resetMovedRect();
				e->changeVectors(0 - e->getXVector() * 0.1, 0 - e->getYVector() * 1.5);
				colFound = true;
			}

			for (Element* e2 : elements) {

				if (colFound)
					break;

				if (e != e2) {
					int colDir = rectsCollide(e->getMovedRect(), e2->getRect());
					
					if (colDir == 1) {
						//e->resetMovedRect();
						e2->changeVectors(e->getXVector() / e2->getElasticity(), e->getYVector() * 0.5);
						e->changeVectors(0 - e->getXVector() * e2->getElasticity(), 0 - e->getYVector() * 0.5);
						colFound = true;
					
					}
					else if (colDir == 2) {
						//e->resetMovedRect();
						e2->changeVectors(e->getXVector() * 0.5, e->getYVector() / e2->getElasticity());
						e->changeVectors(0 - e->getXVector() * 0.5, 0 - e->getYVector() * e2->getElasticity());
						colFound = true;
					}
				}
				
			}

			
		}

		
		if(!colFound)
			e->setMovedRect();
		e->draw(ren);
		e->tick();
		
	}

	

}


EntityManager::EntityManager() {

}
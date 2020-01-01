#include "EntityManager.h"

EntityManager::~EntityManager() {
	physics->~PhysicsHandler();

	for (int i = 0; i < elements.size(); i++)
		elements.at(i)->~Element();
	elements.clear();

	for (int i = 0; i < layers.size(); i++)
		layers.at(i)->~Layer();
	layers.clear();
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
	for (int i = 0; i < elements.size(); i++) {
		if (elements.at(i) == comp) {
			elements.at(i)->~Element();
			elements.erase(elements.begin() + i);
		}
	}
}

void EntityManager::addLayer(Layer* layer){
	layers.push_back(layer);
}

void EntityManager::removeLayer(Layer* layer){
	for (int i = 0; i < layers.size(); i++) {
		if (layers.at(i) == layer) {
			layers.at(i)->~Layer();
			layers.erase(layers.begin() + i);
		}
	}
}

std::vector<Element*> EntityManager::getEntities() {
	return elements;
}

bool EntityManager::outOfBounds(Element* e){
	if (e->getRect()->x > screenX + 10 || e->getRect()->x + e->getRect()->w < -10 ||
		e->getRect()->y > screenY + 10 || e->getRect()->y + e->getRect()->h < -10)
		return true;
	return false;
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
	std::cout << "amt of elements: " << elements.size() << std::endl;

	for (Layer* l : layers) {
		l->moveLayer(-player->getXVector() * l->getMovementSpeed(), -player->getYVector() * l->getMovementSpeed());
		l->drawLayer(ren);
	}

	bool colFound = false;

	for (Element* e : elements) {
		
		physics->applyGravityVector(e);
		if (e->collidable) {
			if(e == player)
				if (physics->windowElementCollide(e))
					colFound = true;
			for (Element* e2 : elements) {
				if (colFound)	
					break;
				if (physics->elementsCollide(e, e2))
					colFound = true;
			}

			for (Layer* l : layers) {
				if (l->isCollidable() && !colFound) {
					for(Element* el : l->elements)
						if (physics->elementsCollide(e, el))
							colFound = true;
				}
			}

		}

		player->resetMovedRect();
		
		if (!colFound) { 
			e->setMovedRect(); 
		}
		e->draw(ren);
		e->tick();

		if (outOfBounds(e))
			removeElement(e);
	}

	if(!colFound)
		for (Layer* l : layers) 
			l->setMovedLayer();
		

	
}




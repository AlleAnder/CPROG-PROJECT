#include "EntityManager.h"

EntityManager::~EntityManager() {
	physics->~PhysicsHandler();

	for (std::vector<Element*>::iterator it = elements.begin(); it != elements.end();) {
		(*it)->~Element();
		it = elements.erase(it);
	}
	elements.clear();

	for (std::vector<Layer*>::iterator it = bLayer.begin(); it != bLayer.end();) {
		(*it)->~Layer();
		it = bLayer.erase(it);
	}
	bLayer.clear();

	for (std::vector<Layer*>::iterator it = fLayer.begin(); it != fLayer.end();) {
		(*it)->~Layer();
		it = fLayer.erase(it);
	}
	fLayer.clear();
	
	player->~PlayableEntity();
}

EntityManager::EntityManager(PhysicsHandler* physics) {
	this->physics = physics; 

	screenX = physics->screenX;
	screenY = physics->screenY;
}

void EntityManager::setPlayer( PlayableEntity* player) {
	this->player = player;
	elements.push_back(player);
}

void EntityManager::addElement( Element* elm) {
	elements.push_back(elm);

}

void EntityManager::removeElement(const Element* comp) {

	for (std::vector<Element*>::iterator it = elements.begin(); it != elements.end();) {
		if (*it == comp) {
			(*it)->~Element();
			it = elements.erase(it);
		}
		else
			it++;
	}
}

void EntityManager::addForeLayer(Layer* layer){
	fLayer.push_back(layer);
}

void EntityManager::addBackLayer(Layer* layer) {
	bLayer.push_back(layer);
}

void EntityManager::removeLayer(Layer* layer){
	for (int i = 0; i < fLayer.size(); i++) 
		if (fLayer.at(i) == layer) {
			fLayer.at(i)->~Layer();
			fLayer.erase(fLayer.begin() + i);
		}
	for (int i = 0; i < bLayer.size(); i++) 
		if (bLayer.at(i) == layer) {
			bLayer.at(i)->~Layer();
			bLayer.erase(bLayer.begin() + i);
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
//	std::cout << "Amt of elements: " << elements.size() << std::endl;

	for (Layer* l : bLayer) { //Handles all backLayers
		if (scrollingMap) //Moves layer in opposite dir of player vectors.
			l->moveLayer(-player->getXVector() * l->getMovementSpeed(), -player->getYVector() * l->getMovementSpeed());
		l->tickLayer();
		l->setMovedLayer();
		l->drawLayer(ren);
		l->tickLayer();
	}

	//SHOOT FIX LATER SOMETHING WIERD IS GOING ON
	Element* shot = player->shoot();
	if (shot != nullptr){
		addElement(shot); //Takes the shot element and adds it to element vector
		//shot->changeVectors(100, 100);
	}
	else
		delete shot;
		
	

	bool colFound = false; //declare var outside loop so i dont have to do it in every itteration of the loop

	for (std::vector<Element*>::iterator it = elements.begin(); it != elements.end(); ) {  // Handles all elements
		colFound = false; 
		
		physics->applyGravityVector((*it));
		
		if ((*it) != player && scrollingMap)
			(*it)->moveFromCurrent(-player->getXVector(), -player->getYVector());

		if ((*it) == player && !scrollingMap)
				if (physics->windowElementCollide(*it))
					colFound = true;
	
		//std::cout << e->isCollidable();
		if ((*it) ->isCollidable()) {
				//std::cout << e->isCollidable();
			

			//THIS IS FOR LAYER COLLISION WHICH DOESNT WORK PROPPERLY yet :(
			for (Layer* l : fLayer) {
				if (l->isCollidable() && !colFound) {
					for (Element* e2 : l->elements) {
						if (colFound)
							break;
						if (physics->elementsCollide((*it), e2))
							colFound = true;
					}
				}
			}

			for (Element* e2 : elements) {
				if (colFound)
					break;
				if (physics->elementsCollide((*it), e2))
					colFound = true;
			}
		}

		if ((*it) == player && scrollingMap)	//Resets the player rect, so that the player stays in the same spot when map is scrolling.
			player->resetMovedRect();

		//if (!colFound)
		(*it)->setMovedRect();
		(*it)->draw(ren);
		(*it)->tick();

		if ((*it) != player && (outOfBounds((*it)) || (*it)->isDead())) {
			delete* it;
			it = elements.erase(it);
		}
		else
			it++;
	}

	for (Layer* l : fLayer) { //Handles colisions within a layer
		for (Element* e1 : l->elements) {
			physics->applyGravityVector(e1);
			colFound = false;
			for (Element* e2 : l->elements) {
				if (colFound)
					break;
				if (physics->elementsCollide(e1, e2))
					colFound = true;
			}
		}

		for (Layer* l2 : fLayer) {
			for (Element* e1 : l->elements) {
				colFound = false;
				for (Element* e2 : l2->elements) {
					if (colFound)
						break;
					if (physics->elementsCollide(e1, e2))
						colFound = true;
				}
			}
		}
	}

	for (Layer* l : fLayer) { //Handles all foreLayers
		if (scrollingMap)	//Moves layer in opposite dir of player vectors.
			l->moveLayer(-player->getXVector() * l->getMovementSpeed(), -player->getYVector() * l->getMovementSpeed());
		l->setMovedLayer();
		l->drawLayer(ren);
		l->tickLayer();
	}

}




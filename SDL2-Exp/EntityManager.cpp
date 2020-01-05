#include "EntityManager.h"

EntityManager::~EntityManager() {
	physics->~PhysicsHandler();

	for (int i = 0; i < elements.size(); i++)
		elements.at(i)->~Element();
	elements.clear();

	for (int i = 0; i < bLayer.size(); i++)
		bLayer.at(i)->~Layer();
	bLayer.clear();

	for (int i = 0; i < fLayer.size(); i++)
		fLayer.at(i)->~Layer();
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
	for (int i = 0; i < elements.size(); i++) {
		if (elements.at(i) == comp) {
			delete elements.at(i);
			elements.erase(elements.begin() + i);
		}
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
	std::cout << "Amt of elements: " << elements.size() << std::endl;

	for (Layer* l : bLayer) { //Handles all backLayers
		if (scrollingMap) //Moves layer in opposite dir of player vectors.
			l->moveLayer(-player->getXVector() * l->getMovementSpeed(), -player->getYVector() * l->getMovementSpeed());
		l->tickLayer();
		l->setMovedLayer();
		l->drawLayer(ren);
	}

	//SHOOT FIX LATER SOMETHING WIERD IS GOING ON
	/*
	Element* shot = player->shoot();
	if (shot != nullptr)
		addElement(shot); //Takes the shot element and adds it to element vector
	else
		delete shot;
		*/
	

	bool colFound = false; //declare var outside loop so i dont have to do it in every itteration of the loop

	for (Element* e : elements) {  // Handles all elements
		colFound = false; 

		physics->applyGravityVector(e);

		if (e != player && scrollingMap)
			e->moveFromCurrent(-player->getXVector(), -player->getYVector());

		if (e == player && !scrollingMap)
				if (physics->windowElementCollide(e))
					colFound = true;

		//std::cout << e->isCollidable();
		if (e->isCollidable()) {
				//std::cout << e->isCollidable();
			

			//THIS IS FOR LAYER COLLISION WHICH DOESNT WORK yet :(
				for (Layer* l : fLayer) {
					if (l->isCollidable() && !colFound) {
						for (Element* e2 : l->elements) {
							if (colFound)
								break;
							if (physics->elementsCollide(e, e2))
								colFound = true;
						}

						
					}
				}

			for (Element* e2 : elements) {
				if (colFound)
					break;
				if (physics->elementsCollide(e, e2))
					colFound = true;
			}
		}

		if (e == player && scrollingMap)	//Resets the player rect, so that the player stays in the same spot when map is scrolling.
			player->resetMovedRect();

		//if (!colFound)
		e->setMovedRect();
		e->draw(ren);
		e->tick();

		if (outOfBounds(e) || e->isDead())
			removeElement(e);
	}

	for (Layer* l : fLayer) {
		for (Element* e1 : l->elements) {
			e1->changeVectors(0,0);
			colFound = false;
			for (Element* e2 : l->elements) {
				if (colFound)
					break;
				if (physics->elementsCollide(e1, e2))
					colFound = true;
			}
		}
	}

	for (Layer* l : fLayer) { //Handles all foreLayers
		if (scrollingMap)	//Moves layer in opposite dir of player vectors.
			l->moveLayer(-player->getXVector() * l->getMovementSpeed(), -player->getYVector() * l->getMovementSpeed());
		l->setMovedLayer();
		l->drawLayer(ren);
	}



	//ATTEMPT TO REMOVE ELMTS
	/*
	int i = 0;
	for (std::vector<Element*>::const_iterator it = elements.begin(); it != elements.end();)
		if (outOfBounds(*it)) {
			delete *it;
			elements.erase(it);
		}
		else {
			it++;
			i++;
		}
	*/
	//THIS SHIT ABOVE DOES NOT WORK LOL AND SHOOTING BULLETS DONT EITHER
}




#include "Layer.h"


Layer::Layer(PlayableEntity* player){
	this->player = player;
}

Layer::~Layer() {
	for (int i = 0; i < elements.size(); i++)
		elements.at(i)->~Element();
	elements.clear();
}

void Layer::addElement(Element* elm){
	elements.push_back(elm);
}

void Layer::removeElement(Element* elm){
	for (int i = 0; i < elements.size(); i++) {
		if (elements.at(i) == elm) {
			elements.at(i)->~Element();
			elements.erase(elements.begin() + i);
		}
	}
}

void Layer::moveLayer(int x, int y){
	for (Element* e : elements) 
		e->moveFromCurrent(x, y);
}

void Layer::setMovedLayer(){
	for (Element* e : elements) 
		e->setMovedRect();
}

void Layer::setElasticity(int el){
	for (Element* e : elements)
		e->setElasticity(el);
}

void Layer::setMovementSpeedToPlayer(int percentage){
	if (percentage > 100) 
		percentage = 100;
	else if (percentage < 0)
		percentage = 0;
	movementSpeed = percentage / 100.0;
}

void Layer::drawLayer(SDL_Renderer* ren){
	for (Element* e : elements) {
		e->tick();
		e->draw(ren);
	}
}

void Layer::setColidable(bool col){
	for (Element* e : elements)
		e->collidable = col;
	collidable = col;
}

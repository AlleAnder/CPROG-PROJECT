#include "Sprite.h"


void Sprite::setCollideCheck(bool(EntityManager::*collideFunc)(SDL_Rect* rect, Vector* vec)){
	this->collideFunc = collideFunc;
}

void Sprite::moveFromCurrent(int x, int y){
	Vector vect;
	(EntityManager->aacollideFunc)(&rect, &vect));

	

}

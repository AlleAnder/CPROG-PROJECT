#include "SALayer.h"

SALayer::SALayer(PlayableEntity* player, int screenX, int screenY) : Layer(player), screenX(screenX), screenY(screenY){}

void SALayer::outOfBoundsCorrect(Element* e) {
	bool moved = false;
	if (e->getRect()->x > screenX) {
		e->moveToNew(0 - e->getRect()->w, rand() % screenY);
		moved = true;
	}
	else if (e->getRect()->x + e->getRect()->w < 0) {
		e->moveToNew(screenX, rand() % screenY);
		moved = true;
	}
	else if (e->getRect()->y > screenY) {
		e->moveToNew(rand() % screenX, 0 - e->getRect()->h);
		moved = true;
	}
	else if (e->getRect()->y + e->getRect()->h < 0) {
		e->moveToNew(rand() % screenX, screenY);
		moved = true;
	}

	if (moved)
		e->changeVectors(-e->getXVector(), -e->getYVector());
}

void SALayer::moveLayer(int x, int y) {
	for (Element* e : elements) {
		e->moveFromCurrent(x, y);
		outOfBoundsCorrect(e);
	}
}
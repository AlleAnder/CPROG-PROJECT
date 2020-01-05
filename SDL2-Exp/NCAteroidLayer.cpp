#include "NCAteroidLayer.h"


NCAteroidLayer::~NCAteroidLayer()
{
}

NCAteroidLayer::NCAteroidLayer(PlayableEntity* player, int screenX, int screenY) : Layer(player), screenX(screenY), screenY(screenY){

}

void NCAteroidLayer::outOfBoundsCorrect(Element* e) {
	if (e->getRect()->x > screenX)
		e->moveToNew(0-e->getRect()->w, e->getRect()->y);
	else if(e->getRect()->x + e->getRect()->w < 0)
		e->moveToNew(screenX, e->getRect()->y);
	else if	(e->getRect()->y > screenY )
		e->moveToNew(e->getRect()->x, 0 - e->getRect()->h);
	else if(e->getRect()->y + e->getRect()->h < 0)
		e->moveToNew(e->getRect()->x, screenY);
}

void NCAteroidLayer::moveLayer(int x, int y) {
	for (Element* e : elements) {
		e->moveFromCurrent(x, y);
		outOfBoundsCorrect(e);
	}
}
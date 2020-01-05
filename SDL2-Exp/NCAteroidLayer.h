#pragma once
#include "Layer.h"
#include "Game.h"

class NCAteroidLayer : public Layer
{
public:
	NCAteroidLayer(PlayableEntity* player, int screenX, int screenY);
	~NCAteroidLayer();

	void moveLayer(int x, int y);

private:

	void outOfBoundsCorrect(Element* e);
	const int screenX, screenY;

	std::vector<Element*> asteroids;

};


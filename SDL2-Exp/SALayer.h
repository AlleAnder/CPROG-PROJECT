#pragma once
#include "Layer.h"



class SALayer : public Layer
{
public:
	SALayer(PlayableEntity* player, int screenX, int screenY);

	void moveLayer(int x, int y);

private:

	void outOfBoundsCorrect(Element* e);
	const int screenX, screenY;
};


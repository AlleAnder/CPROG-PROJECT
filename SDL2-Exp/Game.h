#pragma once
#include <vector>
#include "Element.h"
#include "SDL.h"
#include "GameWindow.h"
#include "PlayableEntity.h"
#include "EntityManager.h"
#include "Background.h"
#include "GameWindow.h"


class Game{
private:
	
	GameWindow* win;
	EntityManager* manager;
	Background* background;
	void draw();

public:
	void run(int maxFPS);

	Game(GameWindow* win, PhysicsHandler* physics, Background* background);
	~Game();

	void setPlayer(PlayableEntity* player);
	void addElement(Element* elm);
	void removeElement(Element* elm);

	void addLayer(Layer* lay);
	void removeLayer(Layer* lay);

	

};


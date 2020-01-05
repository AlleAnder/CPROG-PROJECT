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
	void setHitboxOffset(int px) { manager->setHitboxOffset(px); };
	void addElement(Element* elm);
	void removeElement(Element* elm);


	void addBackLayer(Layer* lay);
	void addForeLayer(Layer* lay);
	void removeLayer(Layer* lay);

	void setScrolling(bool scrolling) { manager->setScrolling(scrolling); };

};


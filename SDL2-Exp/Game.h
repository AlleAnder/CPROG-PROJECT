#pragma once
#include <vector>
#include "Map.h";
#include "Element.h";
#include "SDL.h"
#include "GameWindow.h"
#include "PlayableEntity.h"
#include "EntityManager.h"



class Game
{
private:

	
	GameWindow* win;
	EntityManager manager;

	void draw();


public:
	void run(int maxFPS);

	Game(GameWindow* win);
	~Game();

	void setMap(Map* map) {/*IMPLEMENT THIS LATER*/};
	void setPlayer(PlayableEntity* player);
	void addElement(Element* elm);
	void removeElement(Element* elm);

	

};


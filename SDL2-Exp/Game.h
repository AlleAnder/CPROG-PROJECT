#pragma once
#include <vector>
#include "Map.h";
#include "Element.h";
#include "SDL.h"
#include "GameWindow.h"
#include "PlayableEntity.h"



class Game
{
private:

	std::vector<Element*> elements;
	GameWindow* win;
	PlayableEntity* player;
	
	
	void update();
	void draw();


public:
	void run(int maxFPS);

	Game(GameWindow* win);
	~Game();

	bool setMap(Map* map);
	void setPlayer(PlayableEntity* player);
	bool addElement(Element* comp);
	bool removeElement(Element* comp);

	

};


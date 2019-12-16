#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include "GameWindow.h"
#include "Game.h"
#include "Texture.h"
#include <stdlib.h>  

#include "EXP_ELM.h"
#include "EXP_PLAY.h"

const int WALL = 10;
const int PLAYER = 10;

int main(int argc, char* argv[]) {
	GameWindow win = GameWindow("Hello", 1000, 700);
	Game game(&win);
	Texture texture(win.ren, "C:/Users/savva/source/repos/SDL2-Exp/SDL2-Exp/Images/hello.jpg");

	EXP_PLAY play(600,300, 60, 40, PLAYER);
	play.setTexture(texture.getTexture());
	play.setColidable(true);
	play.setMaxSpeed(100);


	std::vector<Element*> elements;
	for (int i = 0; i < 1; i++) {
		elements.push_back(new EXP_ELM(rand() % 900, rand() % 600, 100, 100, WALL));
	}
	for(Element* e : elements){
		e->setColidable(true);
		e->setMaxSpeed(100);
		e->setElasticity(0);
		e->setColor(155, 133, 0, 255);
		e->setTexture(texture.getTexture());
		game.addElement(e);
	}

	
	game.setPlayer(&play);



	game.run(30);

	game.~Game();
	
	return 0;
}
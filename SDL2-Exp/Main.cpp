#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include "GameWindow.h"
#include "Game.h"
#include "Texture.h"

#include "EXP_ELM.h"
#include "EXP_PLAY.h"

const int WALL = 10;
const int PLAYER = 10;

int main(int argc, char* argv[]) {
	GameWindow win = GameWindow("Hello", 1000, 700);
	Game game(&win);
	Texture texture(win.ren, "C:/Users/savva/source/repos/SDL2-Exp/SDL2-Exp/Images/hello.jpg");

	EXP_PLAY play(600,300, 100, 40, PLAYER);
	play.setTexture(texture.getTexture());
	play.setColidable(true);
	play.setMaxSpeed(1000);

	EXP_ELM elm(0, 600, 1000, 100, WALL);
	elm.setElasticity(70);
	
	elm.setColidable(true);

	EXP_ELM elm3(700, 100, 100, 100, WALL);
	EXP_ELM elm4(0, 450, 100, 100, WALL);
	elm3.setColidable(true);
	elm4.setColidable(true);
	elm3.setMaxSpeed(1000);

	elm.setTexture(texture.getTexture());

	elm3.setColor(155, 133, 0, 255);
	elm4.setColor(155, 133, 0, 255);

	game.addElement(&elm);

	game.addElement(&elm3);
	game.addElement(&elm4);
	game.setPlayer(&play);



	game.run(30);

	game.~Game();
	
	return 0;
}
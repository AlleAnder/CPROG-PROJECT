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

	EXP_PLAY play(600,600, 100, 40, PLAYER);
	play.setTexture(texture.getTexture());
	play.setColidable(true);

	EXP_ELM elm(200, 200, 100, 100, WALL);
	EXP_ELM elm2(400, 600, 100, 100, WALL);
	elm.setColidable(true);
	elm2.setColidable(true);

	elm.setTexture(texture.getTexture());
	elm2.setColor(155, 133, 0, 255);

	game.addElement(&elm);
	game.addElement(&elm2);
	game.setPlayer(&play);

	game.run(30);

	game.~Game();
	
	return 0;
}
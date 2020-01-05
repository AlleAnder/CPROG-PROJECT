#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include "GameWindow.h"
#include "Game.h"
#include "Texture.h"
#include <stdlib.h> 
#include "Background.h"
#include "Layer.h"

#include "Asteroid.h"
#include "Player.h"
#include "Enemy.h"
#include "NCAteroidLayer.h"

const int WALL = 10;
const int PLAYER = 10;
const int screenX = 1500, screenY = 700;

int main(int argc, char* argv[]) {
	GameWindow win("The Space Game! i dont even know lmao", screenX, screenY);
	PhysicsHandler physics(0, screenX, screenY);
	Background back(screenX, screenY);
	Texture texture(win.ren, "C:/Users/savva/source/repos/CPROG-PROJECT/SDL2-Exp/Images/space.png");
	
	Game game(&win, &physics, &back);
	game.setScrolling(true);
	
	back.setColor(135,123,123,255);

	Player play(screenX/2,screenY/2, 60, 60, PLAYER);
	play.setTexture(texture.getTexture());
	play.setCollidable(true);
	play.setMaxSpeed(100);

	NCAteroidLayer asL =  NCAteroidLayer(&play, screenX, screenY);
	for (int i = 0; i < 1000; i++) {
		asL.addElement(new Asteroid(rand() % screenX, rand() % screenY, 20, 20, WALL));
	}

	NCAteroidLayer asL2 = NCAteroidLayer(&play, screenX, screenY);
	for (int i = 0; i < 1000; i++) {
		asL2.addElement(new Asteroid(rand() % screenX, rand() % screenY, 10, 10, WALL));
	}

	game.addBackLayer(&asL);
	game.addForeLayer(&asL2);

	
	Layer lay = Layer(&play);
	lay.addElement(new Asteroid(rand() % screenX, rand() % screenY, 100, 100, WALL));
	lay.addElement(new Asteroid(rand() % screenX, rand() % screenY, 10, 100, WALL));
	lay.addElement(new Asteroid(rand() % screenX, rand() % screenY, 100, 10, WALL));
	lay.addElement(new Asteroid(0, screenY - 100, screenX, 100, WALL));
	game.addBackLayer(&lay);
	
	std::vector<Enemy*> elements;
	for (int i = 0; i < 10; i++) {
		elements.push_back(new Enemy(rand() % screenX, rand() % screenY, 10, 10, WALL));
	}
	for(Enemy* e : elements){
		e->setTarget(&play);
		e->setCollidable(true);
		e->setMaxSpeed(1);
		e->setColor(155, 133, 0, 255);
		e->setTexture(texture.getTexture());
		e->setElasticity(10);
		game.addElement(e);
	}
	elements.clear();
	
	game.setPlayer(&play);


	game.run(30);

	game.~Game();
	
	return 0;
}
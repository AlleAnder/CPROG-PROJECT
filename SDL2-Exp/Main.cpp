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
const int screenX = 2000, screenY = 1000;
const std::string path = "C:/Users/savva/source/repos/CPROG-PROJECT/SDL2-Exp/";

int main(int argc, char* argv[]) {
	GameWindow win("The Space Game! i dont even know lmao", screenX, screenY);
	PhysicsHandler physics(0, screenX, screenY);
	Background back(screenX, screenY);
	Texture star(win.ren, (path + "Images/star.png").c_str());
	Texture ship(win.ren, (path + "Images/space.png").c_str());

	Texture* bAsteroidtextures[5] = { new Texture(win.ren, (path + "Images/asteroid1B.png").c_str()), 
									new Texture(win.ren, (path + "Images/asteroid2B.png").c_str()) ,
									new Texture(win.ren, (path + "Images/asteroid3B.png").c_str()) ,
									new Texture(win.ren, (path + "Images/asteroid4B.png").c_str()) ,
									new Texture(win.ren, (path + "Images/asteroid5B.png").c_str()) };
	Texture* Asteroidtextures[5] = { new Texture(win.ren, (path + "Images/asteroid1.png").c_str()),
									new Texture(win.ren, (path + "Images/asteroid2.png").c_str()) ,
									new Texture(win.ren, (path + "Images/asteroid3.png").c_str()) ,
									new Texture(win.ren, (path + "Images/asteroid4.png").c_str()) ,
									new Texture(win.ren, (path + "Images/asteroid5.png").c_str()) };
	
	Game game(&win, &physics, &back);
	game.setScrolling(true);
	
	

	Player play(screenX/2,screenY/2, 60, 60, PLAYER);
	play.setTexture(ship.getTexture());
	play.setCollidable(true);
	play.setMaxSpeed(3);

	NCAteroidLayer starLayer1 =  NCAteroidLayer(&play, screenX, screenY);
	starLayer1.setMovementSpeedToPlayer(30);
	for (int i = 0; i < 100; i++) {
		Element* elm = new Asteroid(rand() % screenX, rand() % screenY, 10, 10, WALL);
		elm->setTexture(star.getTexture());
		starLayer1.addElement(elm);
	}

	NCAteroidLayer starLayer2 = NCAteroidLayer(&play, screenX, screenY);
	starLayer2.setMovementSpeedToPlayer(50);
	for (int i = 0; i < 100; i++) {
		Element* elm = new Asteroid(rand() % screenX, rand() % screenY, 20, 20, WALL);
		elm->setTexture(star.getTexture());
		starLayer2.addElement(elm);
	}

	NCAteroidLayer asL2 = NCAteroidLayer(&play, screenX, screenY);
	
	asL2.setMovementSpeedToPlayer(100);
	for (int i = 0; i < 40; i++) {
		int x = rand() % 100 + 10;
		Element* elm = new Asteroid(rand() % (screenX + 300), rand() % (screenY + 300), x,x, WALL);
		elm->setMaxSpeed(10);
		elm->setTexture(Asteroidtextures[rand() % 5]->getTexture());
		asL2.addElement(elm);
	}


	Element* elm = new Asteroid(rand() % (screenX + 300), rand() % (screenY + 300), 10,10, WALL);
	elm->setCollidable(true);
	elm->setMaxSpeed(10);
	elm->setTexture(Asteroidtextures[rand() % 5]->getTexture());
	game.addElement(elm);

	game.addBackLayer(&starLayer1);
	game.addBackLayer(&starLayer2);
	game.addForeLayer(&asL2);
	asL2.setCollidable(true);
	
	std::vector<Enemy*> elements;
	for (int i = 0; i < 10; i++) {
		elements.push_back(new Enemy(rand() % screenX, rand() % screenY, 10, 10, WALL));
	}
	for(Enemy* e : elements){
		e->setTarget(&play);
		e->setCollidable(true);
		e->setMaxSpeed(2);
		e->setColor(155, 133, 0, 255);
		e->setTexture(ship.getTexture());
		e->setElasticity(10);
		game.addElement(e);
	}

	elements.clear();
	game.setPlayer(&play);


	game.run(30);

	game.~Game();
	
	return 0;
}
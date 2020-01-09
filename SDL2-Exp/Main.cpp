#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include "GameWindow.h"
#include "Game.h"
#include "Texture.h"
#include <stdlib.h> 

#include "Layer.h"

#include "Asteroid.h"
#include "Player.h"
#include "Enemy.h"
#include "SALayer.h"
#include "EnemyLayer.h"
#include "Background.h"

//ELM IDS: player = 1, enemy = 2, asteroid = 3, bullet = 4

const int screenX = 1000, screenY = 700;
const std::string path = "C:/Users/savva/source/repos/CPROG-PROJECT/SDL2-Exp/";

Mix_Chunk* bgm; 
Mix_Chunk* collision; 
Mix_Chunk* shot;
Mix_Chunk* shotCol;
Mix_Chunk* death;

void initSound() {
	if (Mix_OpenAudio(44100, AUDIO_S16SYS, 6, 8192) < 0)
		std::cerr << "Error loading mixer: " << Mix_GetError() << "\n";

	bgm = Mix_LoadWAV((path + "Sounds/zong.wav").c_str());
	death = Mix_LoadWAV((path + "Sounds/death.wav").c_str());
	shot = Mix_LoadWAV((path + "Sounds/shot.wav").c_str());
	shotCol = Mix_LoadWAV((path + "Sounds/shotCol.wav").c_str());
	collision = Mix_LoadWAV((path + "Sounds/collision.mp3").c_str());

	if(bgm == nullptr || collision == nullptr || shot == nullptr || shotCol == nullptr)
		std::cerr << "Could not load audio";
	else {
		bgm->volume = 30;
		death->volume = 20;
		Mix_PlayChannel(-1, bgm, -1);
	}
}

void destroySound() {
	Mix_FreeChunk(bgm);
	Mix_FreeChunk(shot);
	Mix_FreeChunk(shotCol);
	Mix_FreeChunk(death);
	Mix_FreeChunk(collision);
	Mix_CloseAudio();
}

int main(int argc, char* argv[]) {
	GameWindow* win = new GameWindow("The Space Game! i dont even know lmao", screenX, screenY);
	PhysicsHandler* physics = new PhysicsHandler(0, screenX, screenY);
	Background* back = new Background(screenX, screenY);

	//Initializes music and such
	initSound();

	Texture* star = new Texture(win->getRenderer(), (path + "Images/Stars/star.png").c_str());
	Texture* laser = new Texture(win->getRenderer(), (path + "Images/laser.png").c_str());
	Texture* boostingShip = new Texture(win->getRenderer(), (path + "Images/shipON.png").c_str());
	Texture* cruisingShip = new Texture(win->getRenderer(), (path + "Images/shipOFF.png").c_str());
	Texture* enemyShip = new Texture(win->getRenderer(), (path + "Images/enemy.png").c_str());

	Texture* asteroidtextures[] { new Texture(win->getRenderer(), (path + "Images/Asteroids/asteroid1.png").c_str()),
									new Texture(win->getRenderer(), (path + "Images/Asteroids/asteroid2.png").c_str()) ,
									new Texture(win->getRenderer(), (path + "Images/Asteroids/asteroid3.png").c_str()) ,
									new Texture(win->getRenderer(), (path + "Images/Asteroids/asteroid4.png").c_str()) ,
									new Texture(win->getRenderer(), (path + "Images/Asteroids/asteroid5.png").c_str()) };
	

	
	//CREATE PLAYER
	Player* play = new Player(screenX/2,screenY/2, 50, 70,50, 10, collision);
	play->setCruiseTexture(cruisingShip->getTexture());
	play->setMovingTexture(boostingShip->getTexture());
	play->setCollidable(true);
	play->setMaxSpeed(6);

	play->setShotColSound(shotCol);
	play->setShotSound(shot);
	play->setShotTexture(laser->getTexture());
	
	//CREATE GAME
	Game game(win, physics, back, play);
	game.setScrolling(true);
	game.setHitboxOffset(-5);

	//LAYER OF STARS IN FAR BACK
	SALayer* starLayer1 = new SALayer(play, screenX, screenY);
	starLayer1->setMovementSpeedToPlayer(30);
	for (int i = 0; i < 100; i++) {
		int size = rand() % 10 + 2;
		Element* elm = new Asteroid(rand() % screenX, rand() % screenY, size, size);
		elm->setTexture(star->getTexture());
		starLayer1->addElement(elm);
	}

	//LAYER OF STARS IN FRONT OF FAR BACK
	SALayer* starLayer2 = new SALayer(play, screenX, screenY);
	starLayer2->setMovementSpeedToPlayer(60);
	for (int i = 0; i < 20; i++) {
		int size = rand() % 10 + 10;
		Element* elm = new Asteroid(rand() % screenX, rand() % screenY, size, size);
		elm->setTexture(star->getTexture());
		starLayer2->addElement(elm);
	}

	//LAYER OF STARS CLOSEST
	SALayer* starLayer3 = new SALayer(play, screenX, screenY);
	starLayer3->setMovementSpeedToPlayer(90);
	for (int i = 0; i < 10; i++) {
		int size = rand() % 20 + 10;
		Element* elm = new Asteroid(rand() % screenX, rand() % screenY, size, size);
		elm->setTexture(star->getTexture());
		starLayer3->addElement(elm);
	}
	
	//LAYER OF ASTEROIDS
	SALayer* astroidLayer = new SALayer(play, screenX, screenY);
	astroidLayer->setMovementSpeedToPlayer(100);
	for (int i = 0; i <10; i++) {
		int x = rand() % 100 + 20;
		Asteroid* elm = new Asteroid(rand() % (screenX + 300), rand() % (screenY + 300), x,x);
		elm->setColSound(shotCol);
		elm->setMaxSpeed(10);
		elm->setElasticity(50);
		elm->setTexture(asteroidtextures[rand() % 5]->getTexture());
		astroidLayer->addElement(elm);
	}
	astroidLayer->setCollidable(true);
	
	
	//LAYER OF ENEMIES	
	EnemyLayer* enemyLayer = new EnemyLayer(play, screenX, screenY, collision);
	enemyLayer->setEnemyTexture(enemyShip->getTexture());
	enemyLayer->setCollidable(true);
	enemyLayer->waveInterval(20);
	enemyLayer->incDiffPerWave(1);
	enemyLayer->decreaseIntervalTime(5);
	enemyLayer->setEnemyDeathSound(death);
	
	//ADDING EVERYTHING TO THE GAME
	game.addBackLayer(starLayer1);
	game.addBackLayer(starLayer2);
	game.addBackLayer(starLayer3);
	game.addForeLayer(enemyLayer);
	game.addForeLayer(astroidLayer); 

	//RUN!!
	game.run(30);

	game.~Game();

	//Destroy all layers
	delete starLayer1;
	delete starLayer2;
	delete starLayer3;
	delete enemyLayer;
	delete astroidLayer;

	delete win;
	delete back;
	delete physics;
		
	//Destroy all textures
	delete star;
	delete boostingShip;
	delete cruisingShip;
	delete laser;
	delete enemyShip;
	for (int i = 0; i < sizeof(asteroidtextures) / sizeof(Texture); i++)
		delete asteroidtextures[i];

	destroySound();

	return 0;
}



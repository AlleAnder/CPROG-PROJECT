#pragma once
#include "Layer.h"
#include "Enemy.h"

class EnemyLayer : public Layer
{
public:
	EnemyLayer(PlayableEntity* player, int screenX, int screenY);
	~EnemyLayer() { };

	void tickLayer();

	void waveInterval(int interval) { this->interval = interval; };
	void incDiffPerWave(int amtWaves) {	diffInc = amtWaves; };
	void decreaseIntervalTime(int waves) { intDec = waves; };

	void setEnemyTexture(SDL_Texture* texture) { this->texture = texture; }

private:

	void decreaseInterval();
	bool outOfBounds(Element* e);
	void checkAndRemoveElm();
	void makeWave();
	Enemy* makeEnemy();
	SDL_Point* getOutOfWinCords();

	int frameCounter = 1, const screenX, const screenY, fps = 30, currentWave = 0, interval = 10, diffInc = 1, intDec = 1, currentDiff = 1, const enemySize = 50;
	long secondCounter = 0;
	SDL_Texture* texture;

};


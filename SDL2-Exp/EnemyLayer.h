#pragma once
#include "Layer.h"

class EnemyLayer : public Layer
{
public:
	EnemyLayer(PlayableEntity* player, int screenX, int screenY);
	~EnemyLayer() { };

	void tickLayer();

	void waveInterval(int interval);
	void incDiffPerWave(int amtWaves);

private:

	int screenX, screenY, frameCounter, fps = 30;
	long secondCounter;

};


#include "EnemyLayer.h"

EnemyLayer::EnemyLayer(PlayableEntity* player, int screenX, int screenY) : Layer(player), screenX(screenX), screenY(screenY){
}

void EnemyLayer::tickLayer(){
	if (frameCounter % fps) {
		secondCounter++;
		frameCounter = 0;
	}
	else
		frameCounter++;
}

void EnemyLayer::waveInterval(int interval)
{
}

void EnemyLayer::incDiffPerWave(int amtWaves)
{
}



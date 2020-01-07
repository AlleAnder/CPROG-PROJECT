#include "EnemyLayer.h"

EnemyLayer::EnemyLayer(PlayableEntity* player, int screenX, int screenY, Mix_Chunk* col) : Layer(player), screenX(screenX), screenY(screenY), collisionSound(col){
}

void EnemyLayer::tickLayer(){
	if (frameCounter %( fps + 1) == 0) {
		secondCounter++;
		frameCounter = 1;
	}
	else
		frameCounter++;

	if (secondCounter >= interval) {
		makeWave();
		secondCounter = 0;

		if (intDec % currentWave == 0) {
			decreaseInterval();
		}
	}

	//std::cout << secondCounter;
	
	checkAndRemoveElm();


}

void EnemyLayer::decreaseInterval(){
	if (interval >= 10) 
		interval = interval / 1.1;
}

bool EnemyLayer::outOfBounds(Element* e){
	if (e->getRect()->x > screenX + 100 || e->getRect()->x + e->getRect()->w < -100 ||
		e->getRect()->y > screenY + 100 || e->getRect()->y + e->getRect()->h < -100)
		return true;
	return false;
}

void EnemyLayer::checkAndRemoveElm(){
	for (Element* e : elements) {
		if (outOfBounds(e) || e->isDead())
			removeElement(e);
	}
}

void EnemyLayer::makeWave(){
	for (int i = 0; i < currentDiff; i++) {
		elements.push_back(makeEnemy());
	}
	
	currentDiff += diffInc;
	currentWave++;
}

Enemy* EnemyLayer::makeEnemy(){
	SDL_Point point = *getOutOfWinCords();

	Enemy* enemy = new Enemy(point.x, point.y, enemySize, enemySize, 10, 1, collisionSound);
	enemy->setCollidable(true);
	enemy->setMaxSpeed(3);
	enemy->setTarget(player);
	enemy->setTexture(texture);
	
	return enemy;
}

SDL_Point* EnemyLayer::getOutOfWinCords(){
	SDL_Point* point = new SDL_Point();

	switch (rand() % 4) {
	case 0:
		point->x = rand() % screenX;
		point->y = 0 - enemySize;
		break;
	case 1:
		point->x = screenX;
		point->y = rand() % screenY;
		break;
	case 2:
		point->x = rand() % screenX;
		point->y = screenY;
		break;
	case 3:
		point->x = 0 - enemySize;
		point->y = rand() % screenY;
		break;
	}
	return point;
}





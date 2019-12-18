#include "Sprite.h"

void Sprite::rndStats(int min, int max){
	health = rand() % (max - min) + min;
	defence = rand() % (max - min) + min;
	strength = rand() % (max - min) + min;
}

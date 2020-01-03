#pragma once
#include <SDL.h>
#include "DynamicElement.h"
#include "Vector.h"



class Sprite : public Element
{
public:

	virtual void takeDamage(int damage) { health -= damage; };
	virtual void reduceDefence(int reduction, int seconds) {};
	
	

protected:

	Sprite(int x, int y, int w, int h, int ELEMENT_ID) : Element(x, y, w, h, ELEMENT_ID) {};
	~Sprite() {};

	void setHealth(int hp) { health = hp; };
	void setDefence(int def) { defence = def; };
	void setStrength(int str) { strength = str; };
	void rndStats(int min, int max);

	int health = 0, defence = 0, strength = 0;

	

private:

	Sprite(const Sprite& c) = delete;
	const Sprite& operator= (const Sprite& c) = delete;

};


#pragma once
#include <SDL.h>
#include "DynamicElement.h"
#include "Vector.h"



class Sprite : public Element
{
public:

	virtual void takeDamage(int damage) { health -= damage; };
	virtual int inflictDamage() { return strength; }
	void showHealthBar(bool show) { showHealth = show; };

protected:

	Sprite(int x, int y, int w, int h, int ELEMENT_ID, int health, int strength);
	virtual ~Sprite() {};

	void rndStats(int min, int max);
	void draw(SDL_Renderer* ren);
	
	int health, const startingHealth, strength;
	bool showHealth = true;
	
private:

	void updateHealthBar();
	void drawHealthBar(SDL_Renderer* ren);
	SDL_Rect lifeLost, const lifeTot;

	Sprite(const Sprite& c) = delete;
	const Sprite& operator= (const Sprite& c) = delete;

};


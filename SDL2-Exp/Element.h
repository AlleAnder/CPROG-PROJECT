#pragma once
#include <iostream>
#include "SDL.h"
#include "SDL_image.h"
#include "Vector.h"

class Element
{
public:

	virtual void draw(SDL_Renderer* ren);
	virtual void tick() {};

	virtual void moveToNew(int x, int y);
	virtual void moveFromCurrent(int x, int y);

	void setTexture(SDL_Texture* texture) { this->texture = texture; }
	void setColor(int r, int g, int b, int a);
	void setMaxSpeed(int PPF) { vect.setMax(PPF); }

	void setElasticity(double elasticity);
	double getElasticity() { return this->elasticity; }

	SDL_Rect* getMovedRect() { return &movedRect; }
	SDL_Rect* getRect() { return &rect; }
	void setMovedRect() { rect = movedRect; }
	void resetMovedRect() { movedRect = rect; }

	void changeVectors(double x, double y);
	double getXVector() { return vect.vX; }
	double getYVector() { return vect.vY; }

	~Element();

	const int ELEMENT_ID;

	bool collidable = false;
	virtual void onColide(Element* colWith) { std::cout << ELEMENT_ID << std::endl; };

	virtual void mouseDown(Uint8 e) {};
	virtual void mouseUp(Uint8 e) {};

	virtual void keyDown(SDL_Keycode kc) {};
	virtual void keyUp(SDL_Keycode kc) {};

protected:

	Element(int x, int y, int w, int h, int ELEMENT_ID);
	
	SDL_Texture* texture = nullptr;
	SDL_Rect rect;
	Vector vect;
	int r = 0, g = 0, b = 0, a = 255;
	double elasticity = 1;
	
	

private:

	SDL_Rect movedRect; //For collision detection

	Element(const Element& c) = delete;
	const Element& operator= (const Element& c) = delete;

};


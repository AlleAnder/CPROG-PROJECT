#pragma once
#include <math.h>
#include <iostream>
#include <SDL.h>

#define PI 3.14159265

class Vector
{

public:

	Vector() { Vector(0, 0); };
	Vector(double vX, double vY) : vY(vY), vX(vX){};
	~Vector();

	double vX, vY, dirTravel = 0;
	
	void changeVect(double x, double y);
	void setMax(int maxSpeed) { this->maxSpeed = maxSpeed; }
	int getMaxSpeed() { return maxSpeed; };
	SDL_Point* getDirVectors();	
	SDL_Point* getDirVectors(int deg, int sizeOfVector);


private:

	int maxSpeed = 0;
	void setDirTravel(double x, double y);
	

};


#pragma once
#include <math.h>
#include <iostream>

#define PI 3.14159265

class Vector
{

public:

	Vector();
	~Vector();

	double vX = 0, vY = 0, dirTravel = 0;
	

	void changeVect(double x, double y);
	void setMax(int maxSpeed) { this->maxSpeed = maxSpeed; }
	int getMaxSpeed() { return maxSpeed; };
private:

	int maxSpeed = 0;
	void setDirTravel(double x, double y);

};


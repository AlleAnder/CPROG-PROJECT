#pragma once
class Vector
{

public:

	Vector();
	~Vector();

	double vX = 0, vY = 0;

	void changeVect(double x, double y);
	void setMax(int maxSpeed) { this->maxSpeed = maxSpeed; }

private:

	int maxSpeed = 0;
};


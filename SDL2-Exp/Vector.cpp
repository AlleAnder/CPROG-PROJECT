#include "Vector.h"

Vector::Vector()
{
}

Vector::~Vector()
{
}

void Vector::changeVect(double x, double y){
	vX += x;
	vY += y;

	if (vX > maxSpeed)
		vX = maxSpeed;
	else if (vX < 0 - maxSpeed)
		vX = 0 - maxSpeed;
	
	if (vY > maxSpeed)
		vY = maxSpeed;
	else if (vY < 0 - maxSpeed)
		vY = 0 - maxSpeed;
	
}

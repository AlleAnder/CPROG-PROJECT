#include "Vector.h"

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
	
	setDirTravel(vX, vY);
}

SDL_Point* Vector::getDirVectors(){
	return getDirVectors(dirTravel, 1.0);
}

SDL_Point* Vector::getDirVectors(int deg, double sizeOfVector){
	deg -= 90;
	SDL_Point* vect = new SDL_Point{ (int)(cos(deg * PI / 180) * sizeOfVector), (int)(sin(deg * PI / 180) * sizeOfVector) };
	return vect;
}

void Vector::setDirTravel(double x, double y){
	double angle;
	if (x == 0 && y == 0)
		angle = 0;
	else
		angle = atan((x) / (y)) * 180 / PI;

	if (y == 0) {
		if (x >= 0)
			dirTravel = 90;
		else
			dirTravel = 270;
	}
	else
	if (x <= 0) {
		if (y <= 0) {	//sec 4
			dirTravel = -angle + 360;
		}
		else {			//sec 3
			dirTravel = -angle +180;
		}
	}
	else {
		if (y <= 0) {	//sec 1
			dirTravel = -angle;
		}
		else {			//sec 2
			dirTravel = -angle + 180;
		}
	}


	
}

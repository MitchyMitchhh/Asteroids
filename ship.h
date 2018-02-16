#ifndef ship_h
#define ship_h

#define SHIP_SIZE 10

#define ROTATE_AMOUNT 5
#define THRUST_AMOUNT 0.2 

#include "flyingObject.h"


// Put your Ship class here
class Ship: public FlyingObject 
{
private:
	int angle;
//	Point _position;
	//Velocity _velocity;
public:
	Ship();
	int getAngle()
	{
		return angle;
	}
	void moveLeft();
	void moveRight();
	void moveForward();
	void draw();

};

#endif /* ship_h */

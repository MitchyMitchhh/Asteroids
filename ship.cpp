#include "ship.h"
#include "flyingObject.h"
#include "velocity.h"
#include "uiDraw.h"
#include <iostream>

using namespace std;

// Put your ship methods here

Ship::Ship()
{
	setAlive(true);
	angle = 90;
	size = SHIP_SIZE;
}

void Ship::moveForward()
{
	float dx = THRUST_AMOUNT * (-sin(M_PI *  angle / 180.0));
	float dy = THRUST_AMOUNT * (cos(M_PI * angle / 180.0));

	Velocity myVelocity(dx + getVelocity().getDx(), dy + getVelocity().getDy());

	//cerr << myVelocity.getDx() << endl;
	//cerr << myVelocity.getDy() << endl;

	setVelocity(myVelocity);
}

void Ship::moveLeft()
{
	angle -= ROTATE_AMOUNT;
}

void Ship::moveRight()
{
	angle += ROTATE_AMOUNT;
}

void Ship:: draw()
{
	drawShip(_position, angle, true);
}
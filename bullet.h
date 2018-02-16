#ifndef bullet_h
#define bullet_h

#define BULLET_SPEED 5
#define BULLET_LIFE 40


#include "flyingObject.h"
#include "velocity.h"
#include "point.h"
#include "ship.h"
#include "uiDraw.h"

// Put your Bullet class here
class Bullet : public FlyingObject
{
private:
	int counter;
public:
	Bullet()
	{
		setAlive(true);
		size = 0;
		counter = 0;
		_position.setY(0);
		_position.setX(0);
	}
	void draw()
	{
		drawDot(getPoint());
		//Ship ship;
		if (counter <= 40)
			counter++;
		else
			_alive = false;

	}
	void fire(Point point, float angle)
	{
		float dx = BULLET_SPEED * (cos(M_PI / 180.0 * (angle + 90)));
		float dy = BULLET_SPEED * (sin(M_PI / 180.0 * (angle + 90)));
		//set dx and dy to velocity
		Velocity myVelocity(dx, dy);
		setVelocity(myVelocity);
		setPoint(point);

	}
};

#endif /* bullet_h */

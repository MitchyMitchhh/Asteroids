#ifndef FLYINGOBJECT_H
#define FLYINGOBJECT_H
#define _USE_MATH_DEFINES

#include <math.h>
#include "point.h"
#include "velocity.h"

class FlyingObject
{
protected:
	Point _position;
	Velocity _velocity;
	bool _alive;
	int size;
public:
	Point getPoint() const
	{
		return _position;
	}
	Velocity & getVelocity()
	{
		return _velocity;
	}
	void setPoint(Point position)
	{
		_position = position;
	}
	void setVelocity(Velocity velocity)
	{
		_velocity = velocity;
	}
	bool isAlive()
	{
		return _alive;
	}
	void setAlive(bool alive)
	{
		_alive = alive;
	}
	void kill()
	{
		setAlive(false);
	}
	void virtual draw() = 0;
	void advance()
	{
		float currentX = _velocity.getDx();
		_position.addX(currentX);

		_position.addX(_velocity.getDx());

		float currentY = _velocity.getDy();
		_position.addY(currentY);

		_position.addY(_velocity.getDy());
	}

	int getSize() const
	{
		return size;
	}

	virtual void wrap()
	{
		if (getPoint().getX() > 200)
			_position.setX(-200);

		if (getPoint().getY() > 200)
			_position.setY(-200);

		if (getPoint().getX() < -200)
			_position.setX(200);

		if (getPoint().getY() < -200)
			_position.setY(200);
	}
};




#endif /* FLYINGOBJECT_H */

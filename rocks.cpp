#include "rocks.h"
#include "uiDraw.h"
#include "point.h"

#include <vector>

// Put your Rock methods here
Rock::Rock()
{
	_rotationAngle = random(0, 360);
	_rotationSpeed = 0;
	_radius = 0;
	_alive = true;
}

void Rock :: advance()
{
	FlyingObject::advance();
	_rotationAngle += _rotationSpeed;
	_rotationAngle %= 360;
}

BigRock::BigRock()
{
	int startX = random(-200, 200);
	int startY = random(-200, 200);
	int startAngle = random(0, 360);
	float dx = (-cos(M_PI / 180.0 * startAngle));
	float dy = (-cos(M_PI / 180.0 * startAngle)); 
	
	_velocity.setDx(dx);
	_velocity.setDy(dy);

	_position.setX(startX);
	_position.setY(startY);

	size = BIG_ROCK_SIZE;

	_radius = BIG_ROCK_SIZE;
	_rotationSpeed = BIG_ROCK_SPIN;
}

void BigRock::draw()
{
	drawLargeAsteroid(_position, _rotationAngle);
}

void BigRock::breakApart(std::vector<Rock*> & rocks, std::vector<Rock*>::iterator & it)
{
	Rock* rock1 = NULL;
	rock1 = new MediumRock();
	it = rocks.insert(it, rock1);
	
	point.setY(_position.getY());
	point.setX(_position.getX());
	rock1->setPoint(point);
	
	velocity.setDx(_velocity.getDx());
	velocity.setDy(_velocity.getDy() + 1);
	rock1->setVelocity(velocity);


	Rock* rock2 = NULL;
	rock2 = new MediumRock();
	it = rocks.insert(it, rock2);
	
	point.setY(_position.getY());
	point.setX(_position.getX());
	rock2->setPoint(point);

	velocity.setDx(_velocity.getDx());
	velocity.setDy(_velocity.getDy() -1);
	rock2->setVelocity(velocity);

	Rock* rock3 = NULL;
	rock3 = new SmallRock();
	it = rocks.insert(it, rock3);

	point.setY(_position.getY());
	point.setX(_position.getX());
	rock3->setPoint(point);

	velocity.setDx(_velocity.getDx() + 2);
	velocity.setDy(_velocity.getDy());
	rock3->setVelocity(velocity);
}



//Medium Rock

MediumRock::MediumRock()
{
	int startX = random(-200, 200);
	int startY = random(-200, 200);
	int startAngle = random(0, 360);
	float dx = (-cos(M_PI / 180.0 * startAngle));
	float dy = (-cos(M_PI / 180.0 * startAngle));

	_velocity.setDx(dx);
	_velocity.setDy(dy);

	_position.setX(startX);
	_position.setY(startY);

	size = MEDIUM_ROCK_SIZE;

	_radius = MEDIUM_ROCK_SIZE;
	_rotationSpeed = MEDIUM_ROCK_SPIN;
}

void MediumRock::draw()
{
	drawMediumAsteroid(_position, _rotationAngle);
}

void MediumRock::breakApart(std::vector<Rock*> & rocks, std::vector<Rock*>::iterator & it)
{
	Rock* rock2 = NULL;
	rock2 = new SmallRock();
	it = rocks.insert(it, rock2);

	point.setY(_position.getY());
	point.setX(_position.getX());
	rock2->setPoint(point);

	velocity.setDx(_velocity.getDx() + 3);
	velocity.setDy(_velocity.getDy());
	rock2->setVelocity(velocity);

	Rock* rock3 = NULL;
	rock3 = new SmallRock();
	it = rocks.insert(it, rock3);

	point.setY(_position.getY());
	point.setX(_position.getX());
	rock3->setPoint(point);

	velocity.setDx(_velocity.getDx() -3);
	velocity.setDy(_velocity.getDy());
	rock3->setVelocity(velocity);
}

//Small Rock
SmallRock::SmallRock()
{
	int startX = random(-200, 200);
	int startY = random(-200, 200);
	int startAngle = random(0, 360);
	float dx = (-cos(M_PI / 180.0 * startAngle));
	float dy = (-cos(M_PI / 180.0 * startAngle));

	_velocity.setDx(dx);
	_velocity.setDy(dy);

	_position.setX(startX);
	_position.setY(startY);

	size = SMALL_ROCK_SIZE;

	_radius = SMALL_ROCK_SIZE;
	_rotationSpeed = SMALL_ROCK_SPIN;
}

void SmallRock::draw()
{
	drawSmallAsteroid(_position, _rotationAngle);
}

void SmallRock::breakApart(std::vector<Rock*> & rocks, std::vector<Rock*>::iterator & it)
{
	kill();
}


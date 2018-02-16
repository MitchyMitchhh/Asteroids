#ifndef rocks_h
#define rocks_h
/*
#define BIG_ROCK_SIZE 16
#define MEDIUM_ROCK_SIZE 8
#define SMALL_ROCK_SIZE 4

#define BIG_ROCK_SPIN 2
#define MEDIUM_ROCK_SPIN 5
#define SMALL_ROCK_SPIN 10*/

#define BIG_ROCK_SIZE 16
#define MEDIUM_ROCK_SIZE 10
#define SMALL_ROCK_SIZE 6

#define BIG_ROCK_SPIN 2
#define MEDIUM_ROCK_SPIN 5
#define SMALL_ROCK_SPIN 10

#include "flyingObject.h"
#include <vector>


// Define the following classes here:
//   Rock
//   BigRock
//   MediumRock
//   SmallRock


class Rock : public FlyingObject
{
	protected:
		int _radius;
		int _rotationAngle;
		int _rotationSpeed;
		Point point;
		Velocity velocity;

	public:
		Rock();
		virtual void advance();
		virtual void breakApart(std::vector<Rock*> & rocks, std::vector<Rock*>::iterator & it) = 0;

};

class BigRock : public Rock
{
public:
	BigRock();
	virtual void draw();
	virtual void breakApart(std::vector<Rock*> & rocks, std::vector<Rock*>::iterator & it);
};

class MediumRock : public Rock
{
public:
	MediumRock();
	virtual void draw();
	virtual void breakApart(std::vector<Rock*> & rocks, std::vector<Rock*>::iterator & it);
};

class SmallRock : public Rock
{
public:
	SmallRock();
	virtual void draw();
	virtual void breakApart(std::vector<Rock*> & rocks, std::vector<Rock*>::iterator & it);
};

#endif /* rocks_h */


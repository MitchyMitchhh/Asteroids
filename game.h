#ifndef GAME_H
#define GAME_H

#include "uiInteract.h"
#include "point.h"
#include "rocks.h"
#include "ship.h"
#include "bullet.h"
#include <vector> 

using namespace std;


class Game 
{
private:
	vector <Rock* > _rocks;
	vector <Bullet* > _bullets;
	Ship ship;
	Point point;
	int score;
	int frames;
public:
	Game(Point topLeft, Point bottomRight);
	void makeRocks();
	void draw(const Interface & ui);
	void handleInput(const Interface & ui);
	void advance();
	float getClosestDistance(FlyingObject &obj1, FlyingObject &obj2);
	void handleCollisions();
	void cleanUpZombies();
};
#endif /* GAME_H */



/*********************************************************************
 * File: game.cpp
 * Description: Contains the implementaiton of the game class
 *  methods.
 *
 *********************************************************************/

#include "game.h"
#include "rocks.h"
#include "flyingObject.h"
#include "bullet.h"
#include "uiInteract.h"

// These are needed for the getClosestDistance function...
#include <limits>
#include <algorithm>
using namespace std;

#define STARTING_ROCKS 5


Game::Game(Point topLeft, Point bottomRight)
{
   makeRocks();
}

void Game::makeRocks()
{
   //clean up pre existing rocks

   for (int i = 0; i < STARTING_ROCKS; ++i)
   {
	   Rock* theRock = new BigRock();
      _rocks.push_back(theRock);
   }
}

void Game::draw(const Interface & ui)
{
	Point scoreBoard;
	Point score1;
	scoreBoard.setX(point.getX() - 190);
	scoreBoard.setY(point.getY() + 175);
	score1.setX(point.getX() - 190);
	score1.setY(point.getY() + 185);
	drawNumber(scoreBoard, score);
	drawText(score1, "Score:");

	if (ship.isAlive() == true)
	{
		ship.draw();
		frames++;

		for (int i = 0; i < _rocks.size(); ++i)
		{
			_rocks[i]->draw();
		}

		for (vector <Bullet*> ::iterator bulletIt = _bullets.begin(); bulletIt != _bullets.end(); ++bulletIt)
			(**bulletIt).draw();
	}

	else
	{
		Point uDead;
		uDead.setX(point.getX() - 30);
		drawText(uDead, "You died ...");
	}
}

void Game::handleInput(const Interface & ui)
{
	if (ui.isLeft())
	{
		ship.moveLeft();
	}

	if (ui.isRight())
	{
		ship.moveRight();
	}

	if (ui.isUp())
	{
		ship.moveForward();
	}

	// Check for "Spacebar
	if (ui.isSpace())
	{
		
		//bullets.push_back(newBullet);
		Bullet* newBullet = new Bullet();
		newBullet -> fire(ship.getPoint(), ship.getAngle());
		_bullets.push_back(newBullet);
	}
}

void Game::advance()
{
	if (ship.isAlive() == true)
	{
		ship.wrap();
		ship.advance();
	}

		for (int i = 0; i < _rocks.size(); ++i)
		{
			_rocks[i]->wrap();
			_rocks[i]->advance();
		}

		for (vector <Bullet*> ::iterator bulletIt = _bullets.begin(); bulletIt != _bullets.end(); ++bulletIt)
		{
			(**bulletIt).advance();
			(**bulletIt).wrap();
		}

		handleCollisions();
		cleanUpZombies();
	
  }
// You may find this function helpful...

/**********************************************************
 * Function: getClosestDistance
 * Description: Determine how close these two objects will
 *   get in between the frames.
 **********************************************************/

float Game :: getClosestDistance(FlyingObject &obj1, FlyingObject &obj2)
{
   // find the maximum distance traveled
   float dMax = max(abs(obj1.getVelocity().getDx()), abs(obj1.getVelocity().getDy()));
   dMax = max(dMax, abs(obj2.getVelocity().getDx()));
   dMax = max(dMax, abs(obj2.getVelocity().getDy()));
   dMax = max(dMax, 0.1f); // when dx and dy are 0.0. Go through the loop once.
   
   float distMin = std::numeric_limits<float>::max();
   for (float i = 0.0; i <= dMax; i++)
   {
      Point point1(obj1.getPoint().getX() + (obj1.getVelocity().getDx() * i / dMax),
                     obj1.getPoint().getY() + (obj1.getVelocity().getDy() * i / dMax));
      Point point2(obj2.getPoint().getX() + (obj2.getVelocity().getDx() * i / dMax),
                     obj2.getPoint().getY() + (obj2.getVelocity().getDy() * i / dMax));
      
      float xDiff = point1.getX() - point2.getX();
      float yDiff = point1.getY() - point2.getY();
      
      float distSquared = (xDiff * xDiff) +(yDiff * yDiff);
      
      distMin = min(distMin, distSquared);
   }
   
   return sqrt(distMin);
}

void Game::handleCollisions()
{
	// now check for a hit (if it is close enough to any live bullets)
	for (vector <Rock*> ::iterator it = _rocks.begin(); it != _rocks.end(); ++it)
	{
		if (*it != NULL)
		{
			// this bullet is alive, see if its too close
				// BTW, this logic could be more sophisiticated, but this will
				// get the job done for now...
			for (vector <Bullet*> ::iterator bulletIt = _bullets.begin(); bulletIt != _bullets.end(); ++bulletIt)
			{
				if ((**bulletIt).isAlive())
				{
					if (getClosestDistance(**it, **bulletIt) < (**it).getSize() + (**bulletIt).getSize())
					{

						(**it).kill();
						(*it)->breakApart(_rocks, it);
						(**bulletIt).kill();
						if (ship.isAlive() == true)
							score++;
					}
				}
			} // if bullet is alive

		} // for bullets

		for (vector <Rock*> ::iterator it = _rocks.begin(); it != _rocks.end(); ++it)
		{
			if (*it != NULL)
			{
				if ((ship).isAlive())
				{
					if (frames > 50)
					{
						if (getClosestDistance(**it, ship) < (**it).getSize() + (ship).getSize())
						{

							(**it).kill();
							(ship).kill();

						}
					}
				}

			}
		}
	}
	}

void Game::cleanUpZombies()
	{
		vector<Bullet*>::iterator bulletIt = _bullets.begin();
		while (bulletIt != _bullets.end())
		{

			if ( !(*bulletIt)->isAlive()) //&& pBullet != NULL)
			{
				// remove from list and advance
				delete *bulletIt;
				bulletIt = _bullets.erase(bulletIt);
				
			}
			else
			{
				bulletIt++; // advance
			}
		}

		for (vector <Rock*> ::iterator it = _rocks.begin(); it != _rocks.end();)
		{
			
			if ( !(*it)->isAlive())
			{
				// remove from list and advance
				delete *it;
				it = _rocks.erase(it);

			}
			else
			{
				it++; // advance
			}
		}
	}
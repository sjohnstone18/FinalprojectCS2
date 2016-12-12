#include <iostream>
#include "moveableItem.hpp"
#include "Maze.hpp"
#include "Ghost.hpp"
using namespace std;
class Maze;

// constructor
moveableItem::moveableItem()
{
	attack = 5;
}
// gets the x position of moveableItem
int moveableItem::getX()
{
	return x;
}

// sets the x position for moveableItem
void moveableItem::setX(int x)
{
	this->x = x;
}

// gets the y position of moveableItem
int moveableItem::getY() 
{
	return y;
}

// sets the y position of moveableItem
void moveableItem::setY(int y)
{
	this->y = y;
}

// enables the item to move left
void moveableItem::moveLeft(Maze* maze)
{
	if (maze->canmove(x - 1, y))
	{
		this->setX(this->getX() - 1);

	}
}

// enables the item to move right
void moveableItem::moveRight(Maze* maze)
{
	if (maze->canmove(x + 1, y))
	{
		this->setX(this->getX() + 1);

	}
}

// enables the item to move up
void moveableItem::moveUp(Maze* maze)
{
	if (maze->canmove(x, y - 1))
	{
		this->setY(getY() - 1);

	}
}

// enables the item to move down
void moveableItem::moveDown(Maze* maze)
{
	if (maze->canmove(x, y + 1)) {
		this->setY(getY() + 1);

	}
}

// test
void moveableItem::updatePosition(Maze*)
{

}

int moveableItem::getAttackValue()
{
	return attack;
}
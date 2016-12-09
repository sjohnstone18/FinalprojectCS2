#include <iostream>
#include "moveableItem.hpp"
#include "Maze.hpp"
#include "Ghost.hpp"
using namespace std;
class Maze;

int moveableItem::getX()
{
	return x;
}
void moveableItem::setX(int x)
{
	this->x = x;
}
int moveableItem::getY() 
{
	return y;
}
void moveableItem::setY(int y)
{
	this->y = y;
}
void moveableItem::moveLeft(Maze* maze)
{
	if (maze->canmove(x - 1, y))
	{
		this->setX(this->getX() - 1);

	}
}
void moveableItem::moveRight(Maze* maze)
{
	if (maze->canmove(x + 1, y))
	{
		this->setX(this->getX() + 1);

	}
}
void moveableItem::moveUp(Maze* maze)
{
	if (maze->canmove(x, y - 1))
	{
		this->setY(getY() - 1);

	}
}
void moveableItem::moveDown(Maze* maze)
{
	if (maze->canmove(x, y + 1)) {
		this->setY(getY() + 1);

	}
}

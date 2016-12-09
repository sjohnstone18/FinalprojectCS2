#include "Boss.hpp"
#include "Maze.hpp"
#include <iostream>
#include <string>

using namespace std;

Boss::Boss()
{
	x = 0;
	y = 0;
}

void Boss::render()
{
	cout << "X";
}

bool Boss::passThrough()
{
	return false;
}


int Boss::getX()
{
	return x;
}

void Boss::setX(int x)
{
	this->x = x;
}

int Boss::getY()
{
	return y;
}

void Boss::setY(int y)
{
	this->y = y;
}

//
//  Ghost.cpp
//  MazeGrame
//
//  Created by Stephen Johnson on 12/1/16.
//  Copyright © 2016 Glacier Peak Studios LLC. All rights reserved.
//

#include "Ghost.hpp"
#include "Maze.hpp"
#include <iostream>
#include <string>

using namespace std;

Ghost::Ghost()
{
    x = 0;
    y = 0;
}

void Ghost::render()
{
    cout << "9";
}

bool Ghost::passThrough()
{
    return false;
}


int Ghost::getX()
{
    return x;
}

void Ghost::setX(int x)
{
    this->x = x;
}

int Ghost::getY()
{
    return y;
}

void Ghost::setY(int y)
{
    this->y = y;
}

void Ghost::moveLeft(Maze* maze)
{
	if (maze->canmove(x-1, y))
	{
		this->setX(this->getX() - 1);
		
	}
}
void Ghost::moveRight(Maze* maze)
{
	if (maze->canmove(x+1, y))
	{
		this->setX(this->getX() + 1);
		
	}
}

void Ghost::moveUp(Maze* maze)
{
    if (maze->canmove(x, y-1))
    {
		this->setY(getY() - 1);
       
    }
}

void Ghost::moveDown(Maze* maze)
{
	if (maze->canmove(x, y+1)){
		this->setY(getY() + 1);
		
	}
}
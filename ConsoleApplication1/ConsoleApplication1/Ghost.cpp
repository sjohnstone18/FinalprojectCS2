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

// Ghost constructor
Ghost::Ghost(int movement)
{
	this->movement = movement; // pointer setting passed in movement to variable movement
    x = 0;
    y = 0;
	this->setAttack(5);
	health = 10;
}

// renders the Ghost as a 9 displayed to user
void Ghost::render()
{
    cout << "9";
}

// checks if ghosts are passthroughable or not
bool Ghost::passThrough()
{
    return false;
}

// updates ghost positions for vertical and horizontal
void Ghost::updatePosition(Maze* maze)
{
	int dir = rand() % 2;
	if (movement == randomVertical) { // adds 2 to rand value to only include vertical movement options
		dir += 2;
	}

	// Ghost moves left
	if (dir == 0 && maze->canmove(getX() - 1, getY())) // if space is empty or able to passThrough
	{
		setX(getX() - 1);
	}

	// Ghost moves right
	else if (dir == 1 && maze->canmove(getX() + 1, getY()))
	{
		setX(getX() + 1);
	}

	// Ghost moves down
	else if (dir == 2 && maze->canmove(getX(), getY() - 1))
	{
		setY(getY() - 1);
	}

	// Ghost moves up
	else if (dir == 3 && maze->canmove(getX(), getY() + 1))
	{
		setY(getY() + 1);
	}
}


// gets the current health of the ghost
int Ghost::getHealth() 
{
	return health;
}

// attack the character
void Ghost::attack(moveableItem* Hero, Maze* Maze)
{
	Maze->removeItem(Hero);
	health -= Hero->getAttackValue();
}

// commented out code that now belongs in moveableItems
/*
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
*/
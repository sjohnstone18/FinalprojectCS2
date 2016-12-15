#pragma once

#ifndef Boss_hpp
#define Boss_hpp

#include <stdio.h>
#include "MazeItem.hpp"
#include "Character.hpp"
class Maze;

class Boss : public moveableItem
{
public:
	Boss();
	virtual void render();
	virtual bool passThrough();
	int getX();
	void setX(int x);
	int getY();
	void setY(int y);
	void attack(moveableItem* mazeItem, Maze* Maze); // attack the character
	int getHealth(); // get health for the boss
};
#endif
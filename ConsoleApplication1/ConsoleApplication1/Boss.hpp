#pragma once

#ifndef Boss_hpp
#define Boss_hpp

#include <stdio.h>
#include "MazeItem.hpp"
class Maze;

class Boss : public MazeItem
{
private:
	int x;
	int y;
	int health = 100;
public:
	Boss();
	virtual void render();
	virtual bool passThrough();
	int getX();
	void setX(int x);
	int getY();
	void setY(int y);
};
#endif
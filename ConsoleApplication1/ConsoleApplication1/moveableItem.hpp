#pragma once

#ifndef moveableItem_hpp
#define moveableItem_hpp

#include <iostream>
#include "MazeItem.hpp"
using namespace std;
class Maze;

class moveableItem : public MazeItem { // moveableItem is a subclass of the baseclass MazeItem
protected:
	// data field
	int x;
	int y;

public:
	int getX();
	void setX(int x);
	int getY();
	void setY(int y);
	void moveLeft(Maze* maze);
	void moveRight(Maze* maze);
	void moveUp(Maze* maze);
	void moveDown(Maze* maze);
	virtual void updatePosition(Maze*);
};

#endif
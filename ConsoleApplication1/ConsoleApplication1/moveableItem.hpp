#pragma once

#ifndef moveableItem_hpp
#define moveableItem_hpp

#include <iostream>
#include "MazeItem.hpp"
using namespace std;
class Maze;

class moveableItem : public MazeItem { // moveableItem is derived from MazeItem
protected:
	// data field
	int x;
	int y;

private:
	int attack;
	
public:
	moveableItem();
	int getX();
	void setX(int x);
	int getY();
	void setY(int y);
	void moveLeft(Maze* maze);
	void moveRight(Maze* maze);
	void moveUp(Maze* maze);
	void moveDown(Maze* maze);
	virtual void updatePosition(Maze*);
	virtual int getAttackValue();
	virtual int getHealth();
	void setAttack(int num);
	int health;
};

#endif
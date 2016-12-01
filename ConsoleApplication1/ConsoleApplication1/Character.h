#pragma once
#ifndef Character_h
#define Character_h

#include <stdio.h>
#include "MapItem.h"

class Character : public MapItem
{
public:
	virtual void render();
};

/*
private:
	int xPos, yPos;
	int health;


public:
	Character();
	void moveNorth();
	void moveSouth();
	void moveWest();
	void moveEast();
	int getxPos();
	int getyPos();
*/







#endif // !Character_h

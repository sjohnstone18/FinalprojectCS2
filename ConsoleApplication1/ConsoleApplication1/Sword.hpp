#pragma once

#ifndef Sword_hpp
#define Sword_hpp

#include <stdio.h>
#include "MazeItem.hpp"

class Sword : public MazeItem
{
public:
	Sword();
	virtual void render();
	virtual bool passThrough();
	virtual bool pickUp();
	//virtual int hitPoints(); // sword damage
};

#endif
#pragma once

#ifndef Sword_hpp
#define Sword_hpp

#include <stdio.h>
#include "MazeItem.hpp"

class Sword : public MazeItem
{
public:
	virtual void render();
	virtual bool passThrough();
	virtual bool pickUp();
};

#endif
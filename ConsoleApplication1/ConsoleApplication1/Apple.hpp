#pragma once

#ifndef Apple_hpp
#define Apple_hpp

#include <stdio.h>
#include "MazeItem.hpp" // apple is inherited from mazeItem

class Apple : public MazeItem
{
public:
	Apple();
	virtual void render();
	virtual bool passThrough();
	virtual bool pickUp();
};

#endif

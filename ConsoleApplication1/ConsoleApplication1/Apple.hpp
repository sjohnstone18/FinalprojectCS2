#pragma once

#ifndef Apple_hpp
#define Apple_hpp

#include <stdio.h>
#include "MazeItem.hpp"

class Apple : public MazeItem
{
public:
	Apple();
	virtual void render();
	virtual bool passThrough();
	virtual bool pickUp();
	//virtual int ProtectPoints();
};

#endif

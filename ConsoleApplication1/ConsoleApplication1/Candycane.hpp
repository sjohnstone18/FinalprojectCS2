#pragma once

#ifndef Candycane_hpp
#define Candycane_hpp

#include <stdio.h>
#include "MazeItem.hpp"

class Candycane : public MazeItem
{
public:
	Candycane();
	virtual void render();
	virtual bool passThrough();
	virtual bool pickUp();
	//virtual int ProtectPoints();
};

#endif
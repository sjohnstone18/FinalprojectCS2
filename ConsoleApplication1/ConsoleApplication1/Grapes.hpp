#pragma once

#ifndef Grapes_hpp
#define Grapes_hpp

#include <stdio.h>
#include "MazeItem.hpp"

class Grapes : public MazeItem
{
public:
	virtual void render();
	virtual bool passThrough();
	virtual bool pickUp();
};

#endif
#pragma once

#ifndef Shield_hpp
#define Shield_hpp

#include <stdio.h>
#include "MazeItem.hpp"

class Shield : public MazeItem
{
public:
	virtual void render();
	virtual bool passThrough();
	virtual bool pickUp();
};

#endif
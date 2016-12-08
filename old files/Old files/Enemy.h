#pragma once
#ifndef Enemy_h
#define Enemy_h

#include <stdio.h>
#include "MapItem.h"
#include "MazeMap.h"

class Enemy : public MapItem
{
private:
	int enem_x;
	int enem_y;
public:
	virtual void render();

};
#endif
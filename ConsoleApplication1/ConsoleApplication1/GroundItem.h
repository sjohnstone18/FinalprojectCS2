#pragma once
#ifndef GroundItem_h
#define GroundItem_h

#include <stdio.h>
#include "MapItem.h"

class GroundItem : public MapItem
{
private:
	int itemType;
public:
	GroundItem(int i);
	virtual void render();
	virtual bool passThru();
};

#endif /* MazeWall_hpp */

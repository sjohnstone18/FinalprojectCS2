#pragma once
#ifndef MapWall_h
#define MapWall_h

#include <stdio.h>
#include "MapItem.h"

class MapWall : public MapItem
{
private:
	bool mHorizontal;
public:
	MapWall(bool horz);
	virtual void render();
};

#endif /* MazeWall_hpp */

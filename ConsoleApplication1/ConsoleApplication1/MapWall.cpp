#include "MapWall.h"
#include <iostream>
#include <string>

using namespace std;

MapWall::MapWall(bool horz)
{
	mHorizontal = horz;
}

void MapWall::render()
{
	if (mHorizontal)
	{
		cout << "-";
	}
	else
	{
		cout << "|";
	}
}



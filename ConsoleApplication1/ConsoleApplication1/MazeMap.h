#pragma once

#include <iostream>
#include <stdio.h>
#include <string>
#include "MapItem.h"
using namespace std;

class MazeMap {
private:
	MapItem*** map; // this is copy from in class ex. -- look to change this?
	int mapWidth;
	int mapHeight;

	int char_x;
	int char_y;

	MapItem* constructItemForChar(char c);
public:
	MazeMap(string* initialMap, int numLines);
	~MazeMap();

	void LeftMove();
	void RightMove();
	void UpMove();
	void DownMove();

	void render(); // copied from Stephen-- we can improve this

	void updateItemPositions(); // copied from Stephen-- lets try to ammend this
};
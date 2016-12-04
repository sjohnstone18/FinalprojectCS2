#include <iostream>
#include <string>
#include "MazeMap.h"
#include "Character.h"
#include "MapItem.h"
#include "MapWall.h"
//#include "MazeWall"


using namespace std;

MazeMap::MazeMap(string* initialMaze, int numLines)
{
	this->mapHeight = numLines;
	this->mapWidth = (int)initialMaze[0].length();
	this->map = new MapItem**[numLines];

	for (int i = 0; i < this->mapHeight; i++)
	{
		this->map[i] = new MapItem*[this->mapWidth];
		for (int j = 0; j < this->mapWidth; j++)
		{
			map[i][j] = NULL;
		}
	}

	this->char_x = 0;
	this->char_y = 0;

	for (int i = 0; i < this->mapHeight; i++)
	{
		string line = initialMaze[i];
		for (int j = 0; j < line.length(); j++)
		{
			char c = line.at(j);


			//Constructo the object for this location
			map[i][j] = constructItemForChar(c);

			//Check if this is the character and if
			//it is then we need to track its position
			if (map[i][j] != NULL && typeid(*(map[i][j])) == typeid(Character))
			{
				this->char_x = j;
				this->char_y = i;
			}
		}
	}


}


MazeMap::~MazeMap() {

	{
		//Delete the memory of MazeMap for ideal memory management
		for (int i = 0; i < this->mapHeight; i++)
		{
			for (int j = 0; j < this->mapWidth; j++)
			{
				if (map[i][j] != NULL)
				{
					delete map[i][j];
				}
			}
			delete[] map[i];
		}
		delete[] map;


	}
}

MapItem* MazeMap::constructItemForChar(char c)
{
	if (c == '-')
	{
		return new MapWall(true);
	}
	else if (c == '|')
	{
		return new MapWall(false);
	}
	else if (c == '*')
	{
		return new Character();
	}

	return NULL;
				
}



void MazeMap::LeftMove() {

	if (char_x > 0 && (map[char_y][char_x - 1] == NULL || map[char_y][char_x - 1]->passThru()))

	{

		MapItem* character = map[char_y][char_x];
		map[char_y][char_x] = NULL;
		char_x--;
		map[char_y][char_x] = character;
	}
	
}

void MazeMap::RightMove() {

}

void MazeMap::UpMove() {

}

void MazeMap::DownMove() {

}


// function for terminating the program

void MazeMap::render() { // copied from Stephen-- we can improve this
	for (int i = 0; i < this->mapHeight; i++)
	{
		for (int j = 0; j < this->mapWidth; j++)
		{
			if (map[i][j] != NULL)
			{
				map[i][j]->render();
			}
			else
			{
				cout << " ";
			}
		}

		cout << endl;
	}
}


void MazeMap::updateItemPositions() { // copied from Stephen-- lets try to ammend this
	{
		for (int i = 0; i < this->mapHeight; i++)
		{
			for (int j = 0; j < this->mapWidth; j++)
			{
				//Check if maze[i][j] can move
				//if it can move, then randomly move up, down, left, or right
				//and only do it, if that is a valid location.
			}
		}
	}
}
#include <iostream>
#include "Enemy.h"
#include "MazeMap.h"

using namespace std;
// objective: need to move 
void Enemy::render()
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
	cout << "%";
}
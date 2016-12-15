#include "Shield.hpp"
#include <iostream>
#include <string>

using namespace std;

// renders the shield icon to the maze (D)
void Shield::render()
{
	cout << "D";
}

// enables shield to be a passthrough item to the maze
bool Shield::passThrough()
{
	return true;
}

// enables shield to be able to be picked up
bool Shield::pickUp()
{
	return true;
}
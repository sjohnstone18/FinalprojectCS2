#include "Boss.hpp"
#include "Maze.hpp"
#include "moveableItem.hpp"
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

// Boss constructor
Boss::Boss()
{
	x = 0;
	y = 0;
	setAttack(20);
	health = 30;
}

// renders the Boss to the user display
void Boss::render()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	cout << "X";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

// checks if the Boss is a "passThrough" obect (in this case no)
bool Boss::passThrough()
{
	return false;
}

// gets the Boss x position
int Boss::getX()
{
	return x;
}

// sets the Boss x position
void Boss::setX(int x)
{
	this->x = x;
}

// gets the Boss y position
int Boss::getY()
{
	return y;
}

// sets the Boss y position
void Boss::setY(int y)
{
	this->y = y;
}

// gets the boss' health
int Boss::getHealth() 
{
	return health;
}

void Boss::attack(moveableItem* Hero, Maze* Maze) // attack the character
{
	Maze->removeItem(Hero);
	health -= Hero->getAttackValue();
}


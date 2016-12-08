#include "Shield.hpp"
#include <iostream>
#include <string>

using namespace std;

Shield::Shield()
{

}

void Shield::render()
{
	cout << "D";
}

bool Shield::passThrough()
{
	return true;
}

bool Shield::pickUp()
{
	return true;
}
#include "Sword.hpp"
#include <iostream>
#include <string>

using namespace std;

Sword::Sword()
{

}

void Sword::render()
{
	cout << "!";
}

bool Sword::passThrough()
{
	return true;
}

bool Sword::pickUp()
{
	return true;
}
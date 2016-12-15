#include "Sword.hpp"
#include <iostream>
#include <string>

using namespace std;

// renders the sword icon to the display (!)
void Sword::render()
{
	cout << "!";
}

// enables sword to be a passthrough item
bool Sword::passThrough()
{
	return true;
}

// enables sword to be able to be picked up
bool Sword::pickUp()
{
	return true;
}
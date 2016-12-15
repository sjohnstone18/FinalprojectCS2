#include "Candycane.hpp"
#include <iostream>
#include <string>

using namespace std;

Candycane::Candycane()
{

}

void Candycane::render()
{
	cout << "?";
}

bool Candycane::passThrough()
{
	return true;
}

bool Candycane::pickUp()
{
	return true;
}
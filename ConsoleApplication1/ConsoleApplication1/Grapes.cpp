#include "Grapes.hpp"
#include <iostream>
#include <string>

using namespace std;

Grapes::Grapes()
{

}

void Grapes::render()
{
	cout << "%";
}

bool Grapes::passThrough()
{
	return true;
}

bool Grapes::pickUp()
{
	return true;
}
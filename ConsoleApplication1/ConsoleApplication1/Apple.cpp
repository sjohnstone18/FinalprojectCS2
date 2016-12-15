#include "Apple.hpp"
#include <iostream>
#include <string>

using namespace std;

Apple::Apple()
{

}

void Apple::render()
{
	cout << "O";
}

bool Apple::passThrough()
{
	return true;
}

bool Apple::pickUp()
{
	return true;
}
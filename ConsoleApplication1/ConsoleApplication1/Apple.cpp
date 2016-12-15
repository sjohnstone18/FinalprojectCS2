#include "Apple.hpp"
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

// Apple constructor
Apple::Apple()
{

}

// renders the apple logo (O) to the screen
void Apple::render()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	cout << "O";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

// allows apple to be a passthrough object
bool Apple::passThrough()
{
	return true;
}

// allows apple to be picked up
bool Apple::pickUp()
{
	return true;
}
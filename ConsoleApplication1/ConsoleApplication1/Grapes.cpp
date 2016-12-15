#include "Grapes.hpp"
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

// renders the grapes icon to the screen (%)
void Grapes::render()
{
	// changes grape color to purple
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
	cout << "%";
	// changes color back to normal
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

// allows grapes to be a passthrough object
bool Grapes::passThrough()
{
	return true;
}

// allows grapes to be able to be picked up
bool Grapes::pickUp()
{
	return true;
}
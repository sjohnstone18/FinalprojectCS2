#include "Candycane.hpp"
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

// Candycane constructor
Candycane::Candycane()
{

}

// renders candycane symbol (?) to the user
void Candycane::render()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << "?";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

// allows candycane to be a passthrough object
bool Candycane::passThrough()
{
	return true;
}

// allows candycanes to be picked up
bool Candycane::pickUp()
{
	return true;
}
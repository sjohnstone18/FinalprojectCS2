#include "Candycane.hpp"
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

Candycane::Candycane()
{

}

void Candycane::render()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << "?";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

bool Candycane::passThrough()
{
	return true;
}

bool Candycane::pickUp()
{
	return true;
}
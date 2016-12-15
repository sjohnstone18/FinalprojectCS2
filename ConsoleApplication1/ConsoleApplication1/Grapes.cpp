#include "Grapes.hpp"
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

Grapes::Grapes()
{

}

void Grapes::render()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
	cout << "%";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

bool Grapes::passThrough()
{
	return true;
}

bool Grapes::pickUp()
{
	return true;
}
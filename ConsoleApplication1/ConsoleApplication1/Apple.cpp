#include "Apple.hpp"
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

Apple::Apple()
{

}

void Apple::render()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	cout << "O";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

bool Apple::passThrough()
{
	return true;
}

bool Apple::pickUp()
{
	return true;
}
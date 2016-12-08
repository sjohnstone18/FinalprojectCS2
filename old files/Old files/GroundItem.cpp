#include "Grounditem.h"
#include <iostream>
#include <string>

using namespace std;

GroundItem::GroundItem(int i)
{
	itemType = i;
}


void GroundItem::render()
{
	if (itemType == 1)
	{
		cout << "#";
	}
	else if (itemType == 2)
	{
		cout << "@";
	}
}

bool GroundItem::passThru() {

	return true;

}

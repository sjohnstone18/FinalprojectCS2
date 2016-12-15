
//  Created by Stephen Johnson on 11/28/16.
//  Copyright © 2016 Glacier Peak Studios LLC. All rights reserved.
//  Repurposed by Sam and Ian on 12/15/16

#include "MazeItem.hpp"
#include <iostream>
#include <string>

using namespace std;

void MazeItem::render()
{
    cout << " ";
}

bool MazeItem::passThrough()
{
    return true;
}

bool MazeItem::pickUp()
{
    return false;
}

bool MazeItem::edible()
{
    return false;
}

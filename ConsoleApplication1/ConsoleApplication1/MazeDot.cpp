//
//  MazeDot.cpp
//  MazeGrame
//
//  Created by Stephen Johnson on 12/1/16.
//  Copyright © 2016 Glacier Peak Studios LLC. All rights reserved.
//

#include "MazeDot.hpp"
#include <iostream>
#include <string>

using namespace std;

MazeDot::MazeDot()
{
    
}

void MazeDot::render()
{
    cout << ".";
}

bool MazeDot::passThrough()
{
    return true;
}

bool MazeDot::pickUp()
{
    return false;
}

bool MazeDot::edible()
{
    return true;
}

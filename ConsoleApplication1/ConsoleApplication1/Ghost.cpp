//
//  Ghost.cpp
//  MazeGrame
//
//  Created by Stephen Johnson on 12/1/16.
//  Copyright © 2016 Glacier Peak Studios LLC. All rights reserved.
//

#include "Ghost.hpp"
#include <iostream>
#include <string>

using namespace std;

Ghost::Ghost()
{
    x = 0;
    y = 0;
}

void Ghost::render()
{
    cout << "9";
}

bool Ghost::passThrough()
{
    return false;
}


int Ghost::getX()
{
    return x;
}

void Ghost::setX(int x)
{
    this->x = x;
}

int Ghost::getY()
{
    return y;
}

void Ghost::setY(int y)
{
    this->y = y;
}

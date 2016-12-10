//
//  MazeWall.cpp
//  CS172
//
//  Created by Stephen Johnson on 11/22/16.
//  Copyright © 2016 Glacier Peak Studios LLC. All rights reserved.
//

#include "MazeWall.hpp"
#include <iostream>
#include <string>

using namespace std;

MazeWall::MazeWall(bool horz)
{
    mHorizontal = horz;
    mSecretPassage = false; // character not able to pass through walls 
}

// renders all of the maze walls 
void MazeWall::render()
{
    if (mHorizontal)
    {
        cout << "-";
    }
    else
    {
        cout << "|";
    }
}

bool MazeWall::passThrough()
{
    return mSecretPassage;
}

void MazeWall::setPassage(bool p)
{
    mSecretPassage = p;
}



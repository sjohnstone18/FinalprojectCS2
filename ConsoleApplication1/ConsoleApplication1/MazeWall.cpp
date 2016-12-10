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
    mSecretPassage = false; 
}

// renders all of the maze walls to the user display
void MazeWall::render()
{
    if (mHorizontal)
    {
        cout << "-"; // horizontal walls
    }
    else
    {
        cout << "|"; // vertical walls
    }
}

// enables the character to pass through secret walls
bool MazeWall::passThrough()
{
    return mSecretPassage;
}

// sets passage of secret wall
void MazeWall::setPassage(bool p)
{
    mSecretPassage = p;
}



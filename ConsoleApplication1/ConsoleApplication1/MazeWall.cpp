
//  Created by Stephen Johnson on 11/28/16.
//  Copyright © 2016 Glacier Peak Studios LLC. All rights reserved.
//  Repurposed by Sam and Ian on 12/15/16

#include "MazeWall.hpp"
#include <iostream>
#include <string>

using namespace std;

// mazeWall constructor
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
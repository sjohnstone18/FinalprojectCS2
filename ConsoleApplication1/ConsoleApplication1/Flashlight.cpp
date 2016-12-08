//
//  Flashlight.cpp
//  MazeGrame
//
//  Created by Stephen Johnson on 12/1/16.
//  Copyright © 2016 Glacier Peak Studios LLC. All rights reserved.
//

#include "Flashlight.hpp"
#include <iostream>
#include <string>

using namespace std;

Flashlight::Flashlight()
{
    
}

void Flashlight::render()
{
    cout << "f";
}

bool Flashlight::passThrough()
{
    return true;
}

bool Flashlight::pickUp()
{
    return true;
}

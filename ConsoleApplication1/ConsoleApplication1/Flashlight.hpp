//
//  Flashlight.hpp
//  MazeGrame
//
//  Created by Stephen Johnson on 12/1/16.
//  Copyright © 2016 Glacier Peak Studios LLC. All rights reserved.
//

#ifndef Flashlight_hpp
#define Flashlight_hpp

#include <stdio.h>
#include "MazeItem.hpp"

class Flashlight : public MazeItem
{
public:
    Flashlight();
    virtual void render();
    virtual bool passThrough();
    virtual bool pickUp();
};



#endif /* Flashlight_hpp */

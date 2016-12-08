//
//  MazeDot.hpp
//  MazeGrame
//
//  Created by Stephen Johnson on 12/1/16.
//  Copyright © 2016 Glacier Peak Studios LLC. All rights reserved.
//

#ifndef MazeDot_hpp
#define MazeDot_hpp

#include <stdio.h>
#include "MazeItem.hpp"

class MazeDot : public MazeItem
{
public:
    MazeDot();
    virtual void render();
    virtual bool passThrough();
    virtual bool pickUp();
    virtual bool edible();
};



#endif /* MazeDot_hpp */

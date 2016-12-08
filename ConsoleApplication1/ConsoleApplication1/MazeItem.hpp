//
//  MazeItem.hpp
//  CS172
//
//  Created by Stephen Johnson on 11/22/16.
//  Copyright © 2016 Glacier Peak Studios LLC. All rights reserved.
//

#ifndef MazeItem_hpp
#define MazeItem_hpp

#include <stdio.h>

class MazeItem {
public:
    virtual void render();
    virtual bool passThrough();
    virtual bool pickUp();
    virtual bool edible();
};

#endif /* MazeItem_hpp */

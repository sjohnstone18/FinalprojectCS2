
//  Created by Stephen Johnson on 11/28/16.
//  Copyright © 2016 Glacier Peak Studios LLC. All rights reserved.
//  Repurposed by Sam and Ian on 12/15/16

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

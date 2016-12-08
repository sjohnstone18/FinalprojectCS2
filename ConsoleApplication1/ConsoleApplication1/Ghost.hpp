//
//  Ghost.hpp
//  MazeGrame
//
//  Created by Stephen Johnson on 12/1/16.
//  Copyright © 2016 Glacier Peak Studios LLC. All rights reserved.
//

#ifndef Ghost_hpp
#define Ghost_hpp

#include <stdio.h>
#include "MazeItem.hpp"

class Ghost : public MazeItem
{
private:
    int x;
    int y;
public:
    Ghost();
    virtual void render();
    virtual bool passThrough();
    int getX();
    void setX(int x);
    int getY();
    void setY(int y);
    
};



#endif /* Ghost_hpp */

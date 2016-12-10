//
//  MazeWall.hpp
//  CS172
//
//  Created by Stephen Johnson on 11/22/16.
//  Copyright © 2016 Glacier Peak Studios LLC. All rights reserved.
//

#ifndef MazeWall_hpp
#define MazeWall_hpp

#include <stdio.h>
#include "MazeItem.hpp"

class MazeWall : public MazeItem
{
private:
	// data field
    bool mHorizontal;
    bool mSecretPassage;
public:
    MazeWall(bool horz);
    virtual void render();
    virtual bool passThrough();
    void setPassage(bool p);
};

#endif /* MazeWall_hpp */

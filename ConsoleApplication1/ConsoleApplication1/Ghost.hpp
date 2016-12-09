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
class Maze;

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
	void moveLeft(Maze* maze);
	void moveRight(Maze* maze);
	void moveUp(Maze* maze);
	void moveDown(Maze* maze);
	void attack();
	
};



#endif /* Ghost_hpp */

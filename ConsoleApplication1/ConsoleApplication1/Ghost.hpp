
//  Created by Stephen Johnson on 11/28/16.
//  Copyright © 2016 Glacier Peak Studios LLC. All rights reserved.
//  Repurposed by Sam and Ian on 12/15/16

#ifndef Ghost_hpp
#define Ghost_hpp

#include <stdio.h>
#include "MazeItem.hpp"
#include "moveableItem.hpp"
class Maze;

const int randomHorizontal = 0; // sets randomhorizontal ghosts to a value of 0
const int randomVertical = 1; // sets randomvertical ghosts to a value of 1

class Ghost : public moveableItem // Ghosts derives from moveableItem
{
private:
	int movement;
 
public:
    Ghost(int movement);
    virtual void render();
    virtual bool passThrough();
	virtual void updatePosition(Maze*);
	int getHealth();
	void attack(moveableItem* Hero, Maze* Maze);
};

#endif /* Ghost_hpp */

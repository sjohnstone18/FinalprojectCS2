
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
    void render();
	bool passThrough();
	void updatePosition(Maze*);


	// combat functions
	int getHealth(); // gets the current health of the ghosts...wait all ghosts will have the same health..shoot
	void attack(moveableItem* Hero, Maze* Maze); // attack the character


};

#endif /* Ghost_hpp */

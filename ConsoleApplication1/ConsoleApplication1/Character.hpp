//
//  Character.hpp
//  CS172
//
//  Created by Stephen Johnson on 11/22/16.
//  Copyright © 2016 Glacier Peak Studios LLC. All rights reserved.
//

#ifndef Character_hpp
#define Character_hpp

#include <stdio.h>
#include <vector>
#include "MazeItem.hpp"
#include "Ghost.hpp"
#include "moveableItem.hpp"
using namespace std;

class Character : public moveableItem
{
private:
	// data field
	vector<MazeItem*> inventory;
	int armor;
	
public:
    Character();
    ~Character();
	int getArmor();
    void render();
    void addItemToInventory(MazeItem* item);

    void renderInventory();
	int getHealth();
	void attack(moveableItem* mazeItem, Maze* Maze);
};

#endif /* Character_hpp */

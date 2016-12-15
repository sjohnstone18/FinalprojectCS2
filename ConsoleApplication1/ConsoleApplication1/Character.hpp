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
    bool faceLeft;
	bool faceRight;
    vector<MazeItem*> inventory;
    int numItemsEaten;
	//int health = 100;
	int armor;
	
public:
    
    Character();
    ~Character();
	int getArmor();
    virtual void render();
    
    void addItemToInventory(MazeItem* item);
    //void eatItem(MazeItem* item);
	
    //int numberOfItemsEaten();
    
    void renderInventory();
	void renderHealth();
    
	int getHealth(); // gets the current health of the character

    void didMoveLeft();
    void didMoveRight();
    void didMoveUp();
    void didMoveDown();

	void attack(moveableItem* mazeItem, Maze* Maze); // inflicting damage on the ghosts/boss
};

#endif /* Character_hpp */

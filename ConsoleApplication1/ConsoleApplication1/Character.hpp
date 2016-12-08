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
using namespace std;

class Character : public Ghost
{
private:
    bool faceLeft;
    
    vector<MazeItem*> inventory;
    int numItemsEaten;

public:
    
    Character();
    ~Character();
    
    virtual void render();
    
    void addItemToInventory(MazeItem* item);
    void eatItem(MazeItem* item);
    int numberOfItemsEaten();
    
    void renderInventory();
    
    void didMoveLeft();
    void didMoveRight();
    void didMoveUp();
    void didMoveDown();
};

#endif /* Character_hpp */

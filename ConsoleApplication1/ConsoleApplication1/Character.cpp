//
//  Character.cpp
//  CS172
//
//  Created by Stephen Johnson on 11/22/16.
//  Copyright © 2016 Glacier Peak Studios LLC. All rights reserved.
//

#include "Character.hpp"
#include <iostream>
#include <string>


using namespace std;

Character::Character()
{
    faceLeft = true;
    numItemsEaten = 0;
}

Character::~Character()
{
    for (int i = 0; i < inventory.size(); i++)
    {
        MazeItem* item = inventory.at(i);
        delete item;
    }
}

void Character::render()
{
    if (faceLeft)
    {
        cout << "8";
    }
    else
    {
        cout << "8";
    }
}

void Character::didMoveLeft()
{
    faceLeft = true;
}
void Character::didMoveRight()
{
    faceLeft = false;
}
void Character::didMoveUp()
{
    
}
void Character::didMoveDown()
{
    
}

void Character::addItemToInventory(MazeItem* item)
{
    inventory.push_back(item);
}

/*
void Character::eatItem(MazeItem* item)
{
    numItemsEaten++;
    
    //This really isn't very good, but since we are done with it
    //lets delete this here.
    delete item;
}
*/

int Character::numberOfItemsEaten()
{
    return numItemsEaten;
}

void Character::renderInventory()
{
    for (int i = 0; i < inventory.size(); i++)
    {
        MazeItem* item = inventory.at(i);
        if (i > 0)
        {
            cout << ", ";
        }
        item->render();
    }
}



//
//  Character.cpp
//  CS172
//
//  Created by Stephen Johnson on 11/22/16.
//  Copyright © 2016 Glacier Peak Studios LLC. All rights reserved.
//

#include "Character.hpp"
#include "Maze.hpp"
#include "Shield.hpp"
#include "Sword.hpp"
#include <iostream>
#include <string>


using namespace std;

// constructor for Character
Character::Character()
{
    faceLeft = true;
    numItemsEaten = 0;
	health = 100;
	armor = 0;
	this->setAttack(20);
}

// deconstructor for Character
Character::~Character()
{
    for (int i = 0; i < inventory.size(); i++)
    {
        MazeItem* item = inventory.at(i);
        delete item;
    }
}

// renders the character depending on direction character is moving
// ** do we still need this?
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

// checks if the Character moved left
void Character::didMoveLeft()
{
    faceLeft = true;
}

// checks if the Character moved right
void Character::didMoveRight()
{
    faceLeft = false;
}

// 
void Character::didMoveUp()
{
    
}

//
void Character::didMoveDown()
{
    
}

// function that adds item to inventory vector
void Character::addItemToInventory(MazeItem* item)
{
    inventory.push_back(item);
	if (typeid(*item) == typeid(Shield)) {
		this->armor += 3;
	}
	else if (typeid(*item) == typeid(Sword)) {
		this->setAttack(this->getAttackValue()+20);
	}
}


/*
// function that allows character to eat item
void Character::eatItem(MazeItem* item)
{
    numItemsEaten++;
    
    //This really isn't very good, but since we are done with it
    //lets delete this here.
    delete item;
}
*/

// counts the number of items eaten by the character
int Character::numberOfItemsEaten()
{
    return numItemsEaten;
}

// renders the inventory, displays to user in terminal window
void Character::renderInventory()
{
    for (int i = 0; i < inventory.size(); i++) // loops through inventory and checks for items
    {
        MazeItem* item = inventory.at(i);
        if (i > 0)
        {
            cout << ", ";
        }
        item->render();
    }
}

// renders health to the user in the terminal window?
void Character::renderHealth()
{
	// track health points to display to hero?
}

// gets the current health of the character
int Character::getHealth()
{
	return health;
}

void Character::attack(moveableItem* mazeItem, Maze* Maze)// inflicting damage on the ghosts/boss
{
	Maze->removeItem(mazeItem); // kills ghost
	health -= mazeItem->getAttackValue();
	health += armor;// reduces health of character for each char attack
}

int Character::getArmor() {

	return armor;
}


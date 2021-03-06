
//  Created by Stephen Johnson on 11/28/16.
//  Copyright © 2016 Glacier Peak Studios LLC. All rights reserved.
//  Repurposed by Sam and Ian on 12/15/16

#include "Character.hpp"
#include "Maze.hpp"
#include "Shield.hpp"
#include "Sword.hpp"
#include "Apple.hpp"
#include "Grapes.hpp"
#include "Candycane.hpp"
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

// constructor for Character
Character::Character()
{
	health = 100;
	armor = 0;
	this->setAttack(5);
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

// renders the character to the screen
// sets color of character
void Character::render()
{
   
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout << "8";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

// function that adds item to inventory vector
void Character::addItemToInventory(MazeItem* item)
{
    inventory.push_back(item);
	// if shield is in inventory, add to armor
	if (typeid(*item) == typeid(Shield)) {
		this->armor += 3;
	}
	// if sword is in inventory, add to attack value
	else if (typeid(*item) == typeid(Sword)) {
		this->setAttack(this->getAttackValue()+10);
	}
	// if apple is in inventory, add to health
	else if (typeid(*item) == typeid(Apple)) {
		this->health += 5;
	}
	// if grapes are in inventory, add to health
	else if (typeid(*item) == typeid(Grapes)) {
		this->health += 5;
	}
	// if candycane is in inventory, add to health
	else if (typeid(*item) == typeid(Candycane)) {
		this->health += 5;
	}
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


// gets the current health of the character
int Character::getHealth()
{
	return health;
}

// attacks moveableitems (such as ghosts and boss)
void Character::attack(moveableItem* mazeItem, Maze* Maze)
{
	
	health -= mazeItem->getAttackValue();
	health += armor;// reduces health of character for each char attack
	mazeItem->health -= this->getAttackValue();
	if (typeid(*mazeItem) == typeid(Ghost) || typeid(*mazeItem) == typeid(Boss)) {
		if (mazeItem->health <= 0) {
			Maze->removeItem(mazeItem); // kills ghost
		}
	}
}

// gets the current armor value for the user
int Character::getArmor() {
	return armor;
}


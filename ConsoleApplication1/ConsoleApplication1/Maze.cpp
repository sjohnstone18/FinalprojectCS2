
//  Created by Stephen Johnson on 11/28/16.
//  Copyright © 2016 Glacier Peak Studios LLC. All rights reserved.
//  Repurposed by Sam and Ian on 12/15/16

#include <iostream>
#include <string>
#include <vector>
#include "Maze.hpp"
#include "MazeItem.hpp"
#include "Character.hpp"
#include "MazeWall.hpp"
#include "MazeDot.hpp"

// Inventory Items
#include "Flashlight.hpp"
#include "Sword.hpp"
#include "Shield.hpp"
#include "Boss.hpp"
#include "Apple.hpp"
#include "Grapes.hpp"
#include "Candycane.hpp"

// Maze constructor
Maze::Maze(string* initialMaze, int numLines)
{
	// creates new character in the maze
	this->hero = new Character();

	// constructing the maze
	this->mazeHeight = numLines;
    this->mazeWidth = (int)initialMaze[0].length();
    this->maze = new MazeItem**[numLines];
    this->hero->setX(-8); // sets position of hero
	this->hero->setY(-6); // sets position of hero

	// constructs maze
    for (int i = 0; i < this->mazeHeight; i++)
    {
        this->maze[i] = new MazeItem*[this->mazeWidth];
        for (int j = 0; j < this->mazeWidth; j++)
        {
            maze[i][j] = NULL;
        }
    }
    
    for (int i = 0; i < this->mazeHeight; i++)
    {
        string line = initialMaze[i];
        for (int j = 0; j < line.length(); j++)
        {
            char c = line.at(j);
            
            //Construct the object for this location
            MazeItem* item = constructItemForChar(c);
            
            //Check if this is the character and if
            //it is then we need to track its position
            if (item != NULL && typeid(*item) == typeid(Character)) // if type Character
            {
                this->hero = dynamic_cast<Character*>(item);
                this->hero->setX(j);// sets x val of Character location
                this->hero->setY(i); // sets y val of Character location
            }

			// checks if this is the Ghost and tracks Ghost's position
            else if (item != NULL && typeid(*item) == typeid(Ghost)) // if type Ghost
            {
                Ghost* g = dynamic_cast<Ghost*>(item);
                g->setY(i); // sets y val of location
                g->setX(j); // sets x val of location
                this->moveableItems.push_back(g);
            }
			else if (item != NULL && typeid(*item) == typeid(Boss)) // if type Boss
			{
				Boss* b = dynamic_cast<Boss*>(item);
				b->setY(i); // sets y val of location
				b->setX(j); // sets x val of location
				this->moveableItems.push_back(b);
			}
            else
            {
                maze[i][j] = item; // constructs item in maze array
            }
        }
    }
    
}

// Maze deconstructor
Maze::~Maze()
{
    // Delete the memory
    for (int i = 0; i < this->mazeHeight; i++)
    {
        for (int j = 0; j < this->mazeWidth; j++)
        {
            if (maze[i][j] != NULL)
            {
                delete maze[i][j];
            }
        }
        delete[] maze[i];
    }
    delete hero;
    delete[] maze;

}

// constructs different items in the maze based on char
MazeItem* Maze::constructItemForChar(char c)
{
    if (c == '-') // constructs horiztonal maze walls
    {
        return new MazeWall(true);
    }
    else if (c == '+') // constructs hidden passageways
    {
		// hides the ++ to the user
        MazeWall* wall = new MazeWall(true);
        wall->setPassage(true);
        return wall;
    }
    else if (c == '|') // constructs vertical maze walls
    {
        return new MazeWall(false);
    }
    else if (c == '*') // constructs the starting location of the character
    {
		return hero;
    }
    else if (c == '^')// constructs all horizontal ghosts
    {
        return new Ghost(randomHorizontal);
    }
	else if (c == 'V') // constructs all vertical ghosts
	{
		return new Ghost(randomVertical);
	}
	else if (c == '!') // constructs a sword item
	{
		return new Sword();
	}
	else if (c == 'D') // constructs a shield item
	{
		return new Shield();
	}
	else if (c == 'X') // constructs a Boss
	{
		return new Boss();
	}
	else if (c == 'O') // constructs an apple
	{
		return new Apple();
	}
	else if (c == '%') // constructs an apple
	{
		return new Grapes();
	}
	else if (c == '?') // constructs a candycane
	{
		return new Candycane();
	}
	return 0;
}

// checks if the hero moved
void Maze::heroDidMove()
{
    MazeItem* item = maze[this->hero->getY()][this->hero->getX()];
    if (item != NULL && item->edible()) // checks if item is not null and if it is classified as "edible"
    {
        //hero->eatItem(item);
        maze[this->hero->getY()][this->hero->getX()] = NULL; // removes item from maze
    }
    else if (item != NULL && item->pickUp()) // if the item is not null and the used picks it up
    {
        hero->addItemToInventory(item); // the item is added to inventory vector
        maze[hero->getY()][hero->getX()] = NULL; // item is removed from the maze
    }
}

// updeates all "moveable items" based on their positions
void Maze::updateMovableItemPositions()
{
	for (int i = 0; i < moveableItems.size(); i++)
	{
		moveableItem* g = moveableItems.at(i); // ghost pointer at location i
		moveableItem* b = moveableItems.at(i); // boss point at location i
		
		// if the hero and ghost occupy same space, hero attacks ghost (g)
		if (g->getX() == hero->getX() && g->getY() == hero->getY()) {
			hero->attack(g, this);
			goto done;
		}
		// if boss and hero occupy same space, hero attacks boss (b)
		else if (b->getX() == hero->getX() && b->getY() == hero->getY()) {
			hero->attack(b, this);
			goto done;
		}
	}

	// accounts for if ghost "avoids" character
	for (int i = 0; i < moveableItems.size(); i++)
	{
		moveableItem* g = moveableItems.at(i);
		g->updatePosition(this); // pointer to updatePosition for item
		if (g->getX() == hero->getX() && g->getY() == hero->getY()) {
			hero->attack(g, this);
		}
	}

	done:
	MazeItem* item = maze[this->hero->getY()][this->hero->getX()];
	if (item != NULL && item->pickUp()) // if the item is not null and the used picks it up
	{
		hero->addItemToInventory(item); // the item is added to inventory vector
		maze[hero->getY()][hero->getX()] = NULL; // item is removed from the maze
	}


}

// renders the maze for the user
void Maze::render()
{
    for (int i = 0; i < this->mazeHeight; i++)
    {
        for (int j = 0; j < this->mazeWidth; j++)
        {
            if (i == hero->getY() && j == hero->getX())
            {
                hero->render();
            }
            else
            {
                bool rendered = false;
                for (int idx = 0; idx < moveableItems.size() && !rendered; idx++)
                {
                    moveableItem* g = moveableItems.at(idx);
                    if (g->getX() == j && g->getY() == i)
                    {
                        g->render();
                        rendered = true;
                    }
                }

                if (!rendered)
                {
                    if (maze[i][j] != NULL)
                    {
                        maze[i][j]->render();
                    }
                    else
                    {
                        cout << " ";
                    }
                }
            }
        }
        
        cout << endl;
    }
    
	// User Display beneath maze:
	cout << "Character health: " << hero->getHealth() << endl; // displays current character health
	cout << "Character armor: " << hero->getArmor() << endl;
	cout << "Character attack: " << hero->getAttackValue() << endl;
	cout << "Inventory: "; // displays current inventory
	hero->renderInventory();
    cout << endl;
}

// determines if able to move to a space
bool Maze::canmove(int x, int y) {
	return x >= 0 && x<=mazeWidth-1 &&y>=0, y<= mazeHeight-1&& (maze[y][x]==NULL || maze[y][x] -> passThrough());
}

// removes item if it is either killed or picked up
void Maze::removeItem(moveableItem* Item) 
{
	// deletes specific values in vector
	auto it = std::find(moveableItems.begin(), moveableItems.end(), Item);
	if (it != moveableItems.end()) {
		moveableItems.erase(it);
	}
}
//
//  Maze.cpp
//  MazeGrame
//
//  Created by Stephen Johnson on 11/28/16.
//  Copyright © 2016 Glacier Peak Studios LLC. All rights reserved.
//

#include <iostream>
#include <string>
#include "Maze.hpp"
#include "MazeItem.hpp"
#include "Character.hpp"
#include "MazeWall.hpp"
//#include "Ghost.hpp"
#include "MazeDot.hpp"
#include "Flashlight.hpp"
#include "Sword.hpp"
#include "Shield.hpp"
#include "Boss.hpp"


Maze::Maze(string* initialMaze, int numLines)
{
	this->hero = new Character();

	this->mazeHeight = numLines;
    this->mazeWidth = (int)initialMaze[0].length();
    this->maze = new MazeItem**[numLines];
    this->hero->setX(-8);
	this->hero->setY(-6);

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
            if (item != NULL && typeid(*item) == typeid(Character))
            {
                this->hero = dynamic_cast<Character*>(item);
                this->hero->setX(j);
                this->hero->setY(i);
            }
            else if (item != NULL && typeid(*item) == typeid(Ghost))
            {
                Ghost* g = dynamic_cast<Ghost*>(item);
                g->setY(i);
                g->setX(j);
                this->moveableItems.push_back(g);
            }
            else
            {
                maze[i][j] = item;
            }
        }
    }
    
}

Maze::~Maze()
{
    //Delete the memory
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

MazeItem* Maze::constructItemForChar(char c)
{
    if (c == '-')
    {
        return new MazeWall(true);
    }
    else if (c == '+')
    {
        MazeWall* wall = new MazeWall(true);
        wall->setPassage(true);
        return wall;
    }
    else if (c == '|')
    {
        return new MazeWall(false);
    }
    else if (c == '*')
    {
		return hero;
    }
    else if (c == '^')// all horizontal ghosts
    {
        return new Ghost(randomHorizontal);
    }
	else if (c == 'V') // all vertical ghosts
	{
		return new Ghost(randomVertical);
	}
    else if (c == 'F')
    {
        return new Flashlight();
    }
	else if (c == '!') // sword
	{
		return new Sword();
	}
	else if (c == 'D') // shield
	{
		return new Shield();
	}
	else if (c == 'X') // Boss
	{
		return new Boss();
	}
    return new MazeDot();
    
}









void Maze::heroDidMove()
{
    MazeItem* item = maze[this->hero->getY()][this->hero->getX()];
    if (item != NULL && item->edible())
    {
        //hero->eatItem(item);
        maze[this->hero->getY()][this->hero->getX()] = NULL;
    }
    else if (item != NULL && item->pickUp())
    {
        hero->addItemToInventory(item);
        maze[hero->getY()][hero->getX()] = NULL;
    }
}

void Maze::updateMovableItemPositions()
{
	for (int i = 0; i < moveableItems.size(); i++)
	{
		moveableItem* g = moveableItems.at(i);
		g->updatePosition(this);


		// for ghosts that move randomly left to right
	}
}

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
    
    cout << "Score: " << hero->numberOfItemsEaten() << endl;
	cout << "Inventory: " << endl;
	cout << "health: " << endl;
		//eventually << hero->HeroHealth()
    hero->renderInventory();
    cout << endl;

}



bool Maze::canmove(int x, int y) {

	return x >= 0 && x<=mazeWidth-1 &&y>=0, y<= mazeHeight-1&& (maze[y][x]==NULL || maze[y][x] -> passThrough());
}
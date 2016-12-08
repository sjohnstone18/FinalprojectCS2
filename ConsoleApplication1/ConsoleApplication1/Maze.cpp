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
    else if (c == '^')
    {
        return new Ghost();
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
    return new MazeDot();
    
}

void Maze::moveLeft()
{
    if (this->hero->getX() > 0 &&
        (maze[this->hero->getY()][this->hero->getX()-1] == NULL ||
         maze[this->hero->getY()][this->hero->getX()-1]->passThrough()))
    {
		hero->setX(this->hero->getX() - 1);
		hero->didMoveLeft();
        heroDidMove();
    }
}

void Maze::moveRight()
{
    if (this->hero->getX() < this->mazeWidth - 1  &&
        (maze[this->hero->getY()][this->hero->getX()+1] == NULL ||
         maze[this->hero->getY()][this->hero->getX()+1]->passThrough()))
    {
		hero->setX(this->hero->getX() + 1);
        hero->didMoveRight();
        heroDidMove();
    }
}

void Maze::moveUp()
{
    if (this->hero->getY() > 0  &&
        (maze[this->hero->getY()-1][this->hero->getX()] == NULL || maze[this->hero->getY() -1][this->hero->getX()]->passThrough()))
    {
		hero->setY(this->hero->getY() - 1);
        hero->didMoveUp();
        heroDidMove();
    }
}

void Maze::moveDown()
{
    if (this->hero->getY() < this->mazeHeight - 1  &&
        (maze[this->hero->getY()+1][this->hero->getX()] == NULL || maze[this->hero->getY() +1][this->hero->getX()]->passThrough()))
    {
		hero->setY(this->hero->getY() + 1);
        hero->didMoveDown();
        heroDidMove();
    }
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
        Ghost* g = moveableItems.at(i);
        
		

		// for ghosts that move randomly left to right
		int dir = rand() % 2;
        if (dir == 0 && g->getX() > 0 && // moves left
            (maze[g->getY()][g->getX()-1] == NULL || maze[g->getY()][g->getX()-1]->passThrough())) // if space is empty or able to passThrough
        {
            g->setX(g->getX()-1);
        }
        else if (dir == 1 && g->getX() < this->mazeWidth-1 && // moves right
            (maze[g->getY()][g->getX()+1] == NULL || maze[g->getY()][g->getX()+1]->passThrough()))
        {
            g->setX(g->getX()+1);
        }


        else if (dir == 2 && g->getY() > 0 && // moves up
            (maze[g->getY()-1][g->getX()] == NULL || maze[g->getY()-1][g->getX()]->passThrough()))
        {
            g->setY(g->getY()-1);
        }
        else if (dir == 3 && g->getY() < this->mazeHeight-1 && // moves down
                 (maze[g->getY()+1][g->getX()] == NULL || maze[g->getY()+1][g->getX()]->passThrough()))
        {
            g->setY(g->getY()+1);
        }
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
                    Ghost* g = moveableItems.at(idx);
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

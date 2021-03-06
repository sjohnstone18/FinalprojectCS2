
//  Created by Stephen Johnson on 11/28/16.
//  Copyright © 2016 Glacier Peak Studios LLC. All rights reserved.
//  Repurposed by Sam and Ian on 12/15/16

#ifndef Maze_hpp
#define Maze_hpp

#include <stdio.h>
#include <string>
#include <map>
#include "MazeItem.hpp"
#include "Character.hpp"
#include "Ghost.hpp"
#include "moveableItem.hpp"
#include "Boss.hpp"

using namespace std;

class Maze {
private:
	// data field
    int mazeHeight;
    int mazeWidth;
   

    vector<moveableItem*> moveableItems;
	//vector<MazeItem*> mazeItem;
	
    void heroDidMove();
    
    MazeItem* constructItemForChar(char c);
    
public:
	// data field
	//Two dimensional array of MazeItems
	MazeItem*** maze;
	Ghost* ghosts;
    Character* hero;
	Boss* boss;

    Maze(string* initialMaze, int numLines);
    ~Maze();
	bool canmove(int x,int y);
    void render();
    
    void updateMovableItemPositions();

	void removeItem(moveableItem* Item);
};

#endif /* Maze_hpp */

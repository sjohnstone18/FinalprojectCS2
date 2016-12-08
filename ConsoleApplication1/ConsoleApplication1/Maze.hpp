//
//  Maze.hpp
//  MazeGrame
//
//  Created by Stephen Johnson on 11/28/16.
//  Copyright © 2016 Glacier Peak Studios LLC. All rights reserved.
//

#ifndef Maze_hpp
#define Maze_hpp

#include <stdio.h>
#include <string>
#include <map>
#include "MazeItem.hpp"
#include "Character.hpp"
#include "Ghost.hpp"

using namespace std;

class Maze {
private:
    
    //Two dimensional array of MazeItems
    
    
    
    int mazeHeight;
    int mazeWidth;
    int char_x;
    int char_y;
   
    
    vector<Ghost*> moveableItems;
    
    void heroDidMove();
    
    MazeItem* constructItemForChar(char c);
    
public:
	MazeItem*** maze;
	Ghost* ghosts;
    Character* hero;
    Maze(string* initialMaze, int numLines);
    ~Maze();
	bool canmove(int x,int y);
    void render();
    
    void updateMovableItemPositions();
};

#endif /* Maze_hpp */


//  Created by Stephen Johnson on 11/28/16.
//  Copyright © 2016 Glacier Peak Studios LLC. All rights reserved.
//  Repurposed by Sam and Ian on 12/15/16

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stack>
#include <iomanip>
#include <windows.h>

// Header files
#include "MazeItem.hpp"
#include "Character.hpp"
#include "MazeWall.hpp"
#include "Maze.hpp"
#include "Boss.hpp"
#include "Ghost.hpp"


//Window users uncomment this
#define WINDOWS

using namespace std;

#ifdef WINDOWS
#include <conio.h>
#else
#include <unistd.h>
#include <termios.h>
char _getch() {
    char buf = 0;
    struct termios old = {0};
    if (tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0)
        perror ("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
        perror ("tcsetattr ~ICANON");
    return (buf);
}
#endif

int main()
{
	// Welcome screen to user/objective/controls
	cout << "** Welcome to THE MAZE OF DOOM! **" << endl;
	cout << endl;
	cout << "Your objective is to navigate your character, Max (8), through THE MAZE OF DOOM." << endl;
	cout << "In order to defeat the Demogorgon and exit the maze, you must collect all combat items while avoiding ghosts." << endl;
	cout << endl;
	cout << "Controls:" << endl;
	cout << "a = move left" << endl;
	cout << "d = move right" << endl;
	cout << "w = move up" << endl;
	cout << "s = move down" << endl;
	cout << "q = quit the game" << endl;
	cout << endl;
	cout << "Items:" << endl;
	cout << "! = sword" << endl;
	cout << "D = shield" << endl;
	cout << "? = candycane" << endl;
	cout << "8 = Max" << endl;
	cout << "9 = ghost" << endl;
	cout << "X = Boss" << endl;
	cout << "% = Grapes" << endl;
	cout << "O = Apple" << endl;
	cout << endl;
	cout << "Press any key to enter THE MAZE OF DOOM!..." << endl;
	_getch();
	
	// FILE I/O
	string win1;
	ofstream output;
	// create file
	output.open("WinMessage.txt");

	// write to file
	
	output <<
		" / $$    / $$ /$$$$$$   / $$   /$$     /$$      /$$  /$$$$$$ /$$   /$$ / $$\n"
		"|  $$   / $$// $$__  $$ | $$  | $$    | $$  /$ | $$ |_  $$_/| $$$ | $$|  $$\n"
		" \\  $$ / $$/ | $$  \  $$ | $$  | $$    | $$ /$$$| $$   | $$  | $$$$| $$ | $$\n"
		"  \\  $$$$ /  | $$  | $$ | $$  | $$    | $$/$$ $$ $$   | $$  | $$ $$ $$ | $$\n"
		"   \\  $$ /   | $$  | $$ | $$  | $$    | $$$$_  $$$$   | $$  | $$  $$$$ |__/\n"
		"    | $$     | $$  | $$ | $$  | $$    | $$$/ \\  $$$   | $$  | $$\\  $$$     \n"
		"    | $$     | $$$$$$ / |  $$$$$$/    | $$/   \\  $$  /$$$$$$| $$ \\  $$ /$$ \n"
		"    |__/     \\______/   \\______/     |__/     \__ /|______/|__/  \\__/|__/ \n" << endl;
	
		// Generated using patorjk.com

	// close file
	output.close();

    srand(time(NULL));
    const int SIDE = 21;
	
	// ! = sword
	// D = shield
	// ? = Candycane
	// 8 = Character
	// 9 = Ghosts
	// X = Boss
	// % = Grapes
	// O = Apple

	// object is to defeat the boss and exit the maze

    string initialMaze[SIDE] = // very long string of the intial maze 
    {
		"--------------------------------------------------",
		"| *       |    |         ^     |  % |    ^       |",
		"|------   |          |-----|   |   --   |  |-----|",
		"| %   |   |   -------|     |      ^     |  | ?   |",
		"|     |   ^          |   O |--    |-----|  |--   |",
		"|--    ---  V |   ^               |       ^      |",
		"|             |---------|V   |----------|  |     |",
		"|-------------|            ^               |--|  |",
		"| ?   |    |         |---++----|      |      |   |",
		"|     |    |V |      | %     D |  |-----|    |   |",
		"|     |    |  |--|   |---------|V |     |V       |",
		"|-- V            |        ^       |         -----|",
		"|        ^-------|---   -|         --|     ^     |",
		"|----|           ^       |----|     ?|   ----    |",
		"|    |------|--------|V       |------|   | %|    |",
		"|           |      % |        |          |     VV|",
		"|-++------  |   -----|     |   O  |----------|   |",
		"| O  %|        ^           |------| ?            |",
		"|-------|---   |-----  ----|      |--  -|--------|",
		"|  ?        !  |     D        |   |	    X      ",
		"--------------------------------------------------",
    };
    redo: // allows user to restart the game
    Maze* maze = new Maze(initialMaze, SIDE);
    
    bool done = false; // flag
    while (!done)
    {
        //Clear the old state of the maze
#ifdef WINDOWS
        system("cls");
#else
        system("clear");
#endif
        
        
        //Render the current state of the maze
        maze->render();
        
        //Get the users next move
        char move = _getch();
        
        //update the characters position based on user input
        if (move == 'w') // up move
        {
            maze->hero->moveUp(maze);
        }
        else if (move == 'a') // left move
        {
            maze->hero->moveLeft(maze);
        }
        else if (move == 's') // down move
        {
            maze->hero->moveDown(maze);
        }
        else if (move == 'd') // right move
        {
            maze->hero->moveRight(maze);
        }
        else if (move == 'q') // quit
        {
            done = true;
        }
        
        maze->updateMovableItemPositions();

		// outputs you lose
		if (maze->hero->getHealth() < 0)
		{
			done = true;
			system("cls");
			cout << "you lose!" << endl;
		}
		if (maze->hero->getX() == 48 && maze->hero->getY() == 19) {
			//if (true){
			done = true;
			system("cls");
			ifstream win("WinMessage.txt");
			while (getline(win, win1)) {
				cout << win1 << endl;
			}
		}
    }

	// delete maze for proper memory management
    delete maze;

	// allows user to restart the game
	cout << "do you want to play again? (y/n)" << endl;
	string feedback;
	cin >> feedback;
	if (feedback == "y" || feedback == "Y")
		goto redo;
    return 0;
}
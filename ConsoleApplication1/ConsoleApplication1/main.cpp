#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stack>
#include <iomanip>

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

// Questions for Stephen:
// 1.) Tips on designing health and combat tracking
// 2.) Deleting ghosts after they are killed
// ***3.) Creating maze exit?

int main()
{
	string win1;

	// FILE I/O
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
	
		// Generated using 

	// close file
	output.close();

    srand(time(NULL));
    const int SIDE = 21;
	
	// ! = sword
	// D = shield

	// items that add health to character?
	// like food items?

	// object is to defeat all ghosts, collect all items and fight/kill the Boss to exit the maze

	// Ghosts have 20 health each
	// Character has 100 health
	// Boss has 200 health

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
		"|  ?        !  |     D        |   |	    X      ", // this will be the maze exit to beat the game
		"--------------------------------------------------",
    };
    
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
        if (move == 'w')
        {
            maze->hero->moveUp(maze);
        }
        else if (move == 'a')
        {
            maze->hero->moveLeft(maze);
        }
        else if (move == 's')
        {
            maze->hero->moveDown(maze);
        }
        else if (move == 'd')
        {
            maze->hero->moveRight(maze);
        }
        else if (move == 'q')
        {
            done = true;
        }
        
        maze->updateMovableItemPositions();

		// outputing "you win!"
		// x = 45
		// y = 19

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

    return 0;
}
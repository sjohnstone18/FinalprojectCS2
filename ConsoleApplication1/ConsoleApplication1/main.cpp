#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stack>
#include <iomanip>
#include "MazeItem.hpp"
#include "Character.hpp"
#include "MazeWall.hpp"
#include "Maze.hpp"

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
    srand(time(NULL));
    const int SIDE = 21;
	
	// ! = sword
	// D = shield

    string initialMaze[SIDE] =
    {
		"--------------------------------------------------",
		"|   !     |    |         ^     |    |            |",
		"|------   |          |-----|   |   --   |  |-----|",
		"|     |   |   -------|     |            |  |     |",
		"|     |              |     |--    |-----|  |--   |",
		"|--    ---    |   ^               |              |",
		"|             |---------|    |---------|   |     |",
		"|-------------|                            |--|  |",
		"|     |    |         |---++----|      |      |   |",
		"|     |    |  |   *  |         |  |-----|    |   |",
		"|     |    |  |--|   |---------|  |     |        |",
		"|--              |                |         -----|",
		"|         -------|---   -|        --|            |",
		"|----|           ^       |----|      |   ----    |",
		"|    |------|--------|        |------|   |  |    |",
		"|           |        |        |          |       |",
		"|-++------  |   -----|     |      |----------|   |",
		"|     |        ^           |------|              |",
		"|-------|---   |-----  ----|      |-----|-----|  |",
		"|           !  |     D       |         |        |",
		"--------------------------------------------------",
    };
    
    Maze* maze = new Maze(initialMaze, SIDE);
    
    bool done = false;
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
        
        //update the characters position
        if (move == 'w')
        {
            maze->moveUp();
        }
        else if (move == 'a')
        {
            maze->moveLeft();
        }
        else if (move == 's')
        {
            maze->moveDown();
        }
        else if (move == 'd')
        {
            maze->moveRight();
        }
        else if (move == 'q')
        {
            done = true;
        }
        
        maze->updateMovableItemPositions();
    }
    

    delete maze;

    return 0;
}



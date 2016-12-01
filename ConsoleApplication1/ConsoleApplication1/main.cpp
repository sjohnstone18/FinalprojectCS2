#include <iostream>
#include "Character.h"
#include "MapItem.h"
#include "MazeMap.h"

using namespace std;

#define WINDOWS

#ifdef WINDOWS
#include <conio.h>
#else
#include <unistd.h>
#include <termios.h>
char _getch() {
	char buf = 0;
	struct termios old = { 0 };
	if (tcgetattr(0, &old) < 0)
		perror("tcsetattr()");
	old.c_lflag &= ~ICANON;
	old.c_lflag &= ~ECHO;
	old.c_cc[VMIN] = 1;
	old.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, &old) < 0)
		perror("tcsetattr ICANON");
	if (read(0, &buf, 1) < 0)
		perror("read()");
	old.c_lflag |= ICANON;
	old.c_lflag |= ECHO;
	if (tcsetattr(0, TCSADRAIN, &old) < 0)
		perror("tcsetattr ~ICANON");
	return (buf);
}
#endif

int main() {
	const int SIDE = 50; // change based on size of map
	// map could have secret walls
	// certain areas of map have monsters
	// items are scattered around the map

	string initializeMap[SIDE] =
	{
		            "WELCOME TO MERLOCK'S MANSION"
		"--------------------------------------------------",
		"|  #      |                    |    |            |",
		"|------   |-         |-----|   |   --   |  |-----|",
		"|     |   |   -------|     |            |  |     |",
		"|     |              |     |--    |-----|  |--   |",
		"|--    ---    |                   |              |",
		"|             |---------|    |---------|   |     |",
		"|-------------|                            |--|  |",
		"|     |    |         |---------|      |      |   |",
		"|     |    |  |      |         |  |-----|    |   |",
		"|     |    |  |--|   |---------|  |     |        |",
		"|--              |                |         -----|",
		"|         -------|-------|        --|            |",
		"|----|                   |----|      |   ----    |",
		"|    |------|--------|        |------|   |  |    |",
		"|           |        |        |          |       |",
		"|---------  |   -----|     |      |----------|   |",
		"|     |                    |------|              |",
		"|-------|---   |-----  ----|      |-----|-----|  |",
		"|       |      |              |         |        |",
		"--------------------------------------------------",// finish
	};

	//Render the current state of the maze
	maze->render();

	//Get the users next move
	char move = _getch();

	
	// put key inputs here?
		if (move == 'w') {
			map->UpMove();
	}
		else if (move == ) {

		}

		else if (move == ) {

		}

		else if (move == ) {

		}

		else if (move == ) {

		}
}
#include <iostream>
#include "Character.h"
#include "MapItem.h"
#include "MazeMap.h"

using namespace std;

int main() {
	const int SIDE = 50; // change based on size of map in horizontal direction
	// map could have secret walls?

	// certain areas of map have monsters
	// Goblin symbol: -O-
	// Dragon: <o>
	
	// items are scattered around the map
	// ! = sword
	// [] = shield
	// 
	// additional items?

	string initializeMap[SIDE] =
	{
		            "WELCOME TO MERLOCK'S MANSION"
		"--------------------------------------------------",
		"|  #      |    |               |    |            |",
		"|------   |          |-----|   |   --   |  |-----|",
		"|     |   |   -------|     |            |  |     |",
		"|     |              |     |--    |-----|  |--   |",
		"|--    ---    |                   |              |",
		"|             |---------|    |---------|   |     |",
		"|-------------|                            |--|  |",
		"|     |    |         |---------|      |      |   |",
		"|     |    |  |      |         |  |-----|    |   |",
		"|     |    |  |--|   |---------|  |     |        |",
		"|--              |                |         -----|",
		"|         -------|---   -|        --|            |",
		"|----|                   |----|      |   ----    |",
		"|    |------|--------|        |------|   |  |    |",
		"|           |        |        |          |       |",
		"|---------  |   -----|     |      |----------|   |",
		"|     |                    |------|  []          |",
		"|-------|---   |-----  ----|      |-----|-----|  |",
		"|       |   !  |              |         |        |",
		"--------------------------------------------------",
	};

	//key inputs here?
		if (move == 'w' || 'W') {
			map->UpMove();
	}
		else if (move == 'a' || "A") {
			map->LeftMove();
		}

		else if (move == 'd' || "D") {
			map->RightMove();
		}

		else if (move == 's' || "S") {
			map->DownMove();
		}

		else if (move == 'z' || "Z") {
			//  quit the program
		}
}
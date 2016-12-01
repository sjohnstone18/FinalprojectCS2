#include <iostream>
#include "Character.h"
#include "MapItem.h"
#include "MazeMap.h"

using namespace std;

int main() {
	const int SIDE = 40; // change based on size of map
	// map could have secret walls
	// certain areas of map have monsters
	// items are scattered around the map

	string initializeMap[SIDE] =
	{
		"----------------------------------------------",
		"|  #                                   |     |",
		"|------              |-----|           |--   |",
		"|     |       -------|     |           |     |",
		"|     |              |     |           |   --|",
		"|--           |                        |     |",
		"|             |---------|                    |",
		"|-------------|                              |",
		"|     |    |      "
		"|     |    |  |     "
		"|     |    |  |--|        "
		"|--              |                  "
		"|         -------|"
		"|----|                 "
		"|    |------|--------|"
		"|           |        |"
		"|---------  |   -----|"
		"|"
		"|"
		"|"
		"----------------------------------------------",// finish
	};

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
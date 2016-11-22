/// HELLO!!

//
//  Program Name: finalproject
//  Names: Samuel Johnstone, Ian Fisher
//  Class & Section: CS172
//  Date: 11/21/16
//

#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include "Character.h"
using namespace std;

void command();
void canMove(int& n);
void map(Character* me);
void lookAround(Character* me);
void talk(int x, int y);
int get(int x, int  y);
int kill(int x, int y);
Character me;
static int inventory = 0;

int main() {
	while (1 == 1) {

		cout << "Available commands: commands, map, look, north, south, east, west, talk, get, kill" << endl;
		command();
	}
	return 0;
}

void canMove(int& n) {
	if (n < 0) {
		cout << "It appears you have reached the border of your map. For fear of what uncharted lands lay before you, you decide to turn around." << endl;
		n++;
	}
	else if (n > 4) {
		cout << "It appears you have reached the border of your map. For fear of what uncharted lands lay before you, you decide to turn around." << endl;
		n--;
	}
}
void lookAround(Character* me) {
	if (me->getxPos() == 2 && me->getyPos() == 2)
		cout << "you are in a small shack\n";




}
int kill(int x, int y) {
	if (x == 4 && y == 4 && inventory == 3) {
		cout << "You've killed the monster, and his head rolls on the ground.\n";
	}

	return 0;
}
void map(Character* me) {
	string mapArr[5][5];

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			mapArr[i][j] = "[ ]";
			mapArr[me->getxPos()][me->getyPos()] = "[X]";
			cout << mapArr[i][j];
		}
		cout << endl;
	}
	
}
void talk(int x, int y) {
	if (x == 0 && y == 2) {
		if (inventory == 0) {
			cout << "Gorlax says \"I see you are new here. If you want to survive this desert, you'll need a weapon. I happen to have a weapon, and I'll give it to you if you collect me some treasure. I believe there is some out in the desert. Try checking to the northeast.\"" << endl << setw(30) << "You should find that treasure." << endl;
		}
		if (inventory == 2) {
			cout << "\"Contragulations on getting the treasure. Here's your sword.\"\n";
			get(x, y);
			cout << "\"There's a monster in the deep southeast. You should try out the sword. Bring me its head.\"\n";
		}
	}
}
int get(int x, int y) {
	if (x == 4 && y == 1) {
		cout << "You pick up the treasure." << endl;
		inventory = 2;
	}
	else if (x == 0 && y == 2 && inventory == 2) {
		cout << "You have recieved the sword." << endl;
		inventory = 3;
	}
	else if (x == 4 && y == 4 && inventory == 3) {
		cout << "you picked up the head.\n";
		inventory = 4;
	}

	return inventory;
}


void command() {
	string command;
	cin >> command;

	if (command == "map") {
		map(&me);
	}
	else if (command == "north") {
		me.moveNorth();
	}
	else if (command == "south") {
		me.moveSouth();
	}
	else if (command == "east") {
		me.moveEast();
	}
	else if (command == "west") {
		me.moveWest();
	}
	else if (command == "commands") {
		cout << "Available commands: commands, map, look, north, south, east, west, talk, get, kill" << endl;
	}
	else if (command == "look") {
		lookAround(&me);
	}
	else if (command == "talk") {
		// talk(x, y);
	}
	else if (command == "get") {
		//get(x, y);
	}
	else if (command == "kill") {
		//kill(x, y);
	}

}
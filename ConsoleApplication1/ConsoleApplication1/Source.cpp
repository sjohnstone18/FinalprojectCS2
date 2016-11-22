/// HELLO!!

//
//  Program Name: finalproject
//  Names: Samuel Johnstone, Josh Miller, Jacob Brook
//  Class & Section: CS171 & Sec 3
//  Date: 12/17/15
//

#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
using namespace std;

int command();
void canMove(int& n);
void map(int y, int x);
void lookAround(int x, int y);
void talk(int x, int y);
int get(int x, int  y);
int kill(int x, int y);

static int inventory = 0;

int main() {

	cout << "Available commands: commands, map, look, north, south, east, west, talk, get, kill" << endl;
	while (inventory < 4) {
		command();
	}
	system("CLS");
	cout << setw(30) << "Game over. You win.\n" << endl;

	return 0;
}
int command() {
	string command;
	static int x = 2, y = 2;
	
	cin >> command;
	if (command == "map") {
		map(x, y);
	}
	else if (command == "north") {
		y = y - 1;
		canMove(y);
	}
	else if (command == "south") {
		y = y + 1;
		canMove(y);
	}
	else if (command == "east") {
		x = x + 1;
		canMove(x);
	}
	else if (command == "west") {
		x = x - 1;
		canMove(x);
	}
	else if (command == "commands") {
		cout << "Available commands: commands, map, look, north, south, east, west, talk, get, kill" << endl;
	}
	else if (command == "look") {
		lookAround(x, y);
	}
	else if (command == "talk") {
		talk(x, y);
	}
	else if (command == "get") {
		get(x, y);
	}
	else if (command == "kill") {
		kill(x, y);
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
void lookAround(int x, int y) {
	if (x == 2 && y == 2) {
		cout << "Its a old, run-down shack, in the middle of the desert. There are a few bushes laying around. You see a note on the ground, it says in poorly written handwriting, \" come see Gorlax 2 da west \"\n";
	}
	else if (x == 4 && y == 4) {
		if (inventory == 3) {
			cout << "You hear scary gurgling noises coming from a scary cave, and Gorlax the Crapper runs out! He transforms into a giant monster right before your eyes!" << endl;
		}
		else {
			cout << "You see a cave.  It looks scary.  You should stay away.\n";
		}
	}
	else if (x == 0 && y == 2) {
		cout << "Gorlax The Crapper is hanging out.  He's on his porch." << endl;
		if (inventory == 0) {
			cout << "He says \"Hey there! I got a job for you!\"\n";
		}
	}
	else if (x == 4 && y == 1) {
		cout << "You see a chest underneath a small tree." << endl;
	}
}
int kill(int x, int y) {
	if (x == 4 && y == 4 && inventory == 3) {
		cout << "You've killed the monster, and his head rolls on the ground.\n";
	}

	return 0;
}
void map(int y, int x) {
	string mapArr[5][5];

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			mapArr[i][j] = "[ ]";
			mapArr[x][y] = "[X]";
		}
	}
	for (int k = 0; k < 5; k++) {
		for (int l = 0; l < 5; l++) {
			cout << mapArr[k][l];
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
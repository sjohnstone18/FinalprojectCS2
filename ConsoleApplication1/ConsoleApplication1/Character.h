#pragma once
#ifndef Character_h
#define Character_h


class Character {
private:
	int xPos, yPos;
	int health;


public:
	Character();
	void moveNorth();
	void moveSouth();
	void moveWest();
	void moveEast();
	int getxPos();
	int getyPos();


};





#endif // !Character_h

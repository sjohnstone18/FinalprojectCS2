#pragma once
#ifndef Weapon_h
#define Weapon.h


class weapon {
public:
	weapon(int attack, int pierce, int armor);
	void attack(NPC* c);
	void defend();

	// attack functions
	int getattack();
	void setattack();
	
	// defend functions


	// armor functions
	int getarmor();
	void setarmor();

private:
	int armor;
	int attack;
	int pierce;
	int endurance;



};




#endif 
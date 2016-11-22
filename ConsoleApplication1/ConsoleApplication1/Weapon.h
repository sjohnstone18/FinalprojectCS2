#pragma once
#ifndef Weapon_h
#define Weapon.h
#include "npc.h"


class weapon {
public:
	weapon(int attack, int pierce, int armor);
	void attack(NPC* c);

private:
	int armor, attack, pierce;
	//endurance?  things break?

};




#endif 
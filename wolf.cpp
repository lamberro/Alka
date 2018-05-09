#include "stdafx.h"
#include "wolf.h"
#include <string>
#include <iostream>
#include <random>

Wolf::Wolf() {
	name = "Wolf";
	strength = 12;
	toughness = 12;
	hp = 35;
	max_hp = 35;
	speed = 15;
}

//drops 10-20 xp
int Wolf::drop_xp() {
	int xp = rand() % 10;
	xp += 10;
	cout << this->name << " dropped " << xp << " XP." << endl;
	return xp;
}
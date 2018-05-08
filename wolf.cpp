#include "stdafx.h"
#include "wolf.h"
#include <string>
#include <iostream>

Wolf::Wolf() {
	name = "Wolf";
	strength = 12;
	toughness = 12;
	hp = 20;
	max_hp = 100;
	speed = 15;
}

int Wolf::drop_experience() {
	cout << this->name << " dropped 15 XP." << endl;
	return 15;
}
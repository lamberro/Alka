#include "stdafx.h"
#include "spider.h"
#include <iostream>

Spider::Spider() {
	name = "Giant Spider";
	strength = 13;
	toughness = 15;
	hp = 40;
	max_hp = 40;
	speed = 11;
}

/*
80% chance attack
20% chance spit poison
*/
void Spider::choose_action(Entity * a, Entity * b, bool * is_fight) {
	int x = rand() % 100;
	if (x < 80) {
		attack(a, b);
	}
	if (x >= 80) {
		b->poison(b);
	}
}

int Spider::drop_experience() {
	cout << this->name << " dropped 20 XP." << endl;
	return 20;
}
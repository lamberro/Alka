#include "stdafx.h"
#include "crab.h"

#include <iostream>

Crab::Crab() {
	name = "Crab";
	strength = 7;
	toughness = 18;
	hp = 10;
	max_hp = 10;
	speed = 6;
}

void Crab::choose_action(Entity * a, Entity * b, bool * is_fight) {
	int action = rand() % 100;
	if (action < 80) {
		a->attack(a, b);
	}
	else {
		this->crustacean_stance();
	}
}

void Crab::crustacean_stance() {
	cout << this->name << " goes into a crustacean stance!" << endl;
	this->heal(5);
}
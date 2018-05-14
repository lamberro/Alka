#include "stdafx.h"
#include "urchin.h"

#include <iostream>

Urchin::Urchin() {
	name = "Giant Sea Urchin";
	strength = 7;
	toughness = 15;
	hp = 15;
	max_hp = 15;
	speed = 5;
	is_charging = false;
}

/*
if attack is charging, 100% use charged attack
if not...
50% normal attack
50% start charging
*/
void Urchin::choose_action(Entity * a, Entity * b, bool * is_fight) {
	int x = rand() % 100;
	if (is_charging) {
		charge_attack(a, b);
	}
	else {
		if (x < 50) {
			attack(a, b);
		}
		else {
			start_charging();
		}
	}
}

void Urchin::start_charging() {
	cout << "The sea urchin seems to be charging some sort of super powerful attack move!" << endl;
	this->is_charging = true;
}

void Urchin::charge_attack(Entity * a, Entity * b) {
	cout << "The urchin unleashes the charged attack!" << endl;
	int u_strength = this->strength;
	this->strength += 5;
	attack(a, b);
	this->strength = u_strength;
	this->is_charging = false;
}
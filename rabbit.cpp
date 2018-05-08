#include "stdafx.h"
#include "rabbit.h"
#include <random>

using namespace std;

Rabbit::Rabbit() {
	name = "Rabbit";
	strength = 7;
	toughness = 7;
	hp = 15;
	max_hp = 15;
	speed = 12;
}

void Rabbit::choose_action(Entity * a, Entity * b, bool * is_fight) {
	int x = rand() % 100;
	if (x < 90) {
		bool flee = escape(a, b);
		if (!flee)
			*is_fight = true;
		else
			*is_fight = false;
	}
	else {
		attack(a, b);
	}
}
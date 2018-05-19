#include "stdafx.h"
#include "item.h"
#include "berry.h"
#include <iostream>

Berry::Berry() {
	name = "berry";
	description = "It is a handful of healthy berries.";
	consumable = true;
	gen_rarity();
}

void Berry::gen_rarity() {
	int r = rand() % 1000;
	rare = false;
	ultra_rare = false;
	super_ultra_rare = false;
	if (r == 0) {
		super_ultra_rare = true;
		name = "super ultra rare berry";
		description = "This is no ordinary berry! The chances of you getting this are 1 in 1000!";
	}
	else {
		if (r < 11) {
			ultra_rare = true;
			name = "ultra rare berry";
			description = "This is no ordinary berry! Incredible things will happen if you consume this!";
		}
		else {
			if (r < 32) {
				rare = true;
				name = "rare berry";
				description = "This is no ordinary berry! Who knows what will happen if you consume this?";
			}
		}
	}
}

void Berry::consume(Entity * a) {
	
	cout << "Berry raises " << a->get_name() << "'s max HP by 1. Berries are healthy, you know!" << endl;
	a->set_max_hp(a->get_max_hp()+1);
	
	cout << "Berry heals " << a->get_name() << " for 20." << endl;
	a->heal(20);
}

void Berry::consume(Player * a) {
	cout << "Berry raises " << a->get_name() << "'s max HP by 1. Berries are healthy, you know!" << endl;
	a->set_max_hp(a->get_max_hp() + 1);

	cout << "Berry heals " << a->get_name() << " for 20." << endl;
	a->heal(20);

	if (rare) {
		cout << "Berry gives out XP!" << endl;
		a->level_up();
	}
	if (ultra_rare) {
		cout << "Berry gives out lots of XP!" << endl;
		a->level_up();
		a->level_up();
		a->level_up();
	}
	if (super_ultra_rare) {
		cout << "Berry gives out a BUTTLOAD of XP!" << endl;
		a->level_up();
		a->level_up();
		a->level_up();
		a->level_up();
		a->level_up();
		a->level_up();
		a->level_up();
		cout << "Berry DOUBLES max HP!" << endl;
		a->set_max_hp(a->get_max_hp() * 2);
	}
}
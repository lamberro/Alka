#include "stdafx.h"
#include "coast.h"
#include "game.h"
#include "player.h"
#include "entity.h"
#include "crab.h"
#include "urchin.h"
#include <iostream>
#include <random>

/*
60% wander
20% encounter crab
20% urchin
*/
void Coast::choose(Player * hero, Inventory * inv) {
	int x = rand() % 100;
	if (x < 60) {
		wander();
	}
	if (x >= 60 && x < 80) {
		encounter_crab(hero);
	}
	if (x >= 80 && x < 100) {
		encounter_urchin(hero);
	}
}

void Coast::wander() {
	cout << "You decide to wander the coast." << endl;
	cout << "You find nothing." << endl;
}

void Coast::encounter_crab(Player * hero) {
	cout << "You encounter a crab!" << endl;
	Entity * crab = new Crab;
	Game::fight(hero, crab);
	delete crab;
}

void Coast::encounter_urchin(Player * hero) {
	cout << "You encounter a giant urchin!" << endl;
	Entity * urchin = new Urchin;
	Game::fight(hero, urchin);
	delete urchin;
}
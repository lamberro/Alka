#include "stdafx.h"
#include "coast.h"
#include "game.h"
#include "player.h"
#include "entity.h"
#include "crab.h"
#include <iostream>
#include <random>

/*
80% wander
20% encounter crab
*/
void Coast::choose(Player * hero) {
	int x = rand() % 100;
	if (x < 80) {
		wander();
	}
	if (x >= 80 && x < 100) {
		encounter_crab(hero);
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
#include "stdafx.h"
#include "game.h"
#include "entity.h"
#include "wolf.h"
#include "player.h"
#include "forest.h"
#include <iostream>
#include <time.h>
#include <random>

using namespace std;

void Forest::choose(Player * hero) {
	int x = rand() % 100;
	if (x < 20) {
		pick_berries();
	}
	if (x >= 20 && x < 80) {
		wander();
	}
	if (x >= 80) {
		encounter_wolf(hero);
	}
}

void Forest::pick_berries() {
	cout << "You decide to go out and pick berries." << endl;
}

void Forest::wander() {
	cout << "You decide to go out and wander the forests." << endl;
}

void Forest::encounter_wolf(Player * hero) {
	Entity * wolf = new Wolf;
	cout << "You have encountered a wolf!" << endl;
	Game::fight(hero, wolf);
}
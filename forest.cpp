#include "stdafx.h"
#include "game.h"
#include "entity.h"
#include "wolf.h"
#include "rabbit.h"
#include "player.h"
#include "forest.h"
#include <iostream>
#include <time.h>
#include <random>

/*
20% pick berries
20% wander
30% encounter rabbit
30% encounter wolf

3% get lost
*/
void Forest::choose(Player * hero) {
	int x = rand() % 100;
	int lost = rand() % 100;
	if (x < 20) {
		pick_berries();
	}
	if (x >= 20 && x < 40) {
		wander();
	}
	if (x >= 40 && x < 70) {
		encounter_rabbit(hero);
	}
	if (x >= 70 && x < 100) {
		encounter_wolf(hero);
	}
	if (lost < 3) {
		cout << endl << "You get lost and delve deeper into the forest" << endl;
		choose(hero);
	}
	/*
	if (lost >= 3) {
		cout << endl << "You easily make it back to camp." << endl;
	}
	*/
}

void Forest::pick_berries() {
	cout << "You go out and pick berries." << endl;
}

void Forest::wander() {
	cout << "You go out and wander the forests." << endl;
}

void Forest::encounter_wolf(Player * hero) {
	Entity * wolf = new Wolf;
	cout << "You have encountered a wolf!" << endl;
	Game::fight(hero, wolf);
	delete wolf;
}

void Forest::encounter_rabbit(Player * hero) {
	Entity * rabbit = new Rabbit;
	cout << "You have encountered a wild rabbit!" << endl;
	Game::fight(hero, rabbit);
	delete rabbit;
}
#include "stdafx.h"
#include "game.h"
#include "entity.h"
#include "wolf.h"
#include "rabbit.h"
#include "spider.h"
#include "player.h"
#include "forest.h"
#include "berry.h"
#include <iostream>
#include <time.h>
#include <random>

/*
15% pick berries
5% wander
20% encounter rabbit
30% encounter wolf
30% encounter giant spider
3% get lost
*/
void Forest::choose(Player * hero, Inventory * inv) {
	int x = rand() % 100;
	int lost = rand() % 100;
	if (x < 15) {
		pick_berries(inv);
	}
	if (x >= 15 && x < 20) {
		wander();
	}
	if (x >= 20 && x < 40) {
		encounter_rabbit(hero);
	}
	if (x >= 40 && x < 70) {
		encounter_wolf(hero);
	}
	if (x >= 70 && x < 100) {
		encounter_spider(hero);
	}
	if (lost < 3) {
		cout << endl << "You get lost and delve deeper into the forest" << endl;
		choose(hero, inv);
	}
	/*
	if (lost >= 3) {
		cout << endl << "You easily make it back to camp." << endl;
	}
	*/
}

void Forest::pick_berries(Inventory * inv) {
	cout << "You go out and pick berries." << endl;
	Berry * berry = new Berry;
	inv->add_to_inventory(berry);
}

void Forest::wander() {
	cout << "You go out and wander the forests." << endl;
	cout << "You find nothing." << endl;
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

void Forest::encounter_spider(Player * hero) {
	Entity * spider = new Spider;
	cout << "You have encountered a giant spider!" << endl;
	Game::fight(hero, spider);
	delete spider;
}
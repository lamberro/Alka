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
10% pick berries
10% wander
20% encounter rabbit
30% encounter wolf
30% encounter giant spider
3% get lost
*/
void Forest::choose(Player * hero) {
	int x = rand() % 100;
	int lost = rand() % 100;
	if (x < 10) {
		pick_berries(hero);
	}
	if (x >= 10 && x < 20) {
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
		choose(hero);
	}
	/*
	if (lost >= 3) {
		cout << endl << "You easily make it back to camp." << endl;
	}
	*/
}

void Forest::pick_berries(Player * hero) {
	cout << "You go out and pick berries." << endl;
	Berry berry;
	hero->get_inventory()->add_to_inventory(berry);
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
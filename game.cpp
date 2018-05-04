#include "stdafx.h"
#include "game.h"
#include "entity.h"
#include "player.h"
#include "location.h"
#include "forest.h"
#include <iostream>
#include <string>

using namespace std;
Game::Game() {
	this->hero = new Player;
	this->num_locations = 1;
	this->locations = new Location*[num_locations]; //changes with number of locations
	locations[0] = new Forest;
}

Game::~Game() {
	delete hero;
	for (int i = 0; i < num_locations; i++) {
		delete locations[i];
	}
	delete[] locations;
}

Player * Game::get_player() {
	return this->hero;
}

int Game::get_num_locations() {
	return this->num_locations;
}

Location ** Game::get_locations() {
	return this->locations;
}

void Game::set_player(Player * new_hero) {
	this->hero = new_hero;
}

void Game::set_num_locations(int num) {
	this->num_locations = num;
}

void Game::set_locations(Location ** new_locations) {
	this->locations = new_locations;
}

void Game::camp() {
	bool game_running = true;
	while (game_running == true) {
		cout << "You are at your camp. What would you like to do?" << endl;
		cout << "[0] go to the forest." << endl;
		cout << "[1] sleep." << endl;
		cout << "[2] display player info." << endl;
		cout << "[3] quit game." << endl;
		string line;
		getline(cin, line);
		if (line == "0") {
			locations[0]->choose(hero);
		}
		if (line == "1") {
			cout << "You sleep." << endl;
			hero->heal(10);
			cout << "Your health is now: " << hero->get_hp() << "/" << hero->get_max_hp() << endl;
		}
		if (line == "2") {
			cout << "Player info:" << endl;
			hero->display_stats();
		}
		if (line == "3") {
			game_running = false;
		}
	}
}

void Game::fight(Player * a, Entity * b) {
	cout << "You're in a fight!" << endl;
	bool is_fight = true;
	while (is_fight) {
		cout << endl;
		cout << "You: " << endl;
		a->display_stats();
		cout << "Enemy: " << endl;
		b->display_stats();
		cout << "What would you like to do?" << endl;
		cout << "[0] Attack." << endl;
		cout << "[1] Attempt escape." << endl;
		cout << "[2] Just hang around, I guess." << endl;
		string line;
		getline(cin, line);
		if (line == "0") {
			cout << "You swing your fists [not implemented]" << endl;
			//a->attack();
		}
		if (line == "1") {
			int escape = rand() % 100;
			if (escape <= 50) {
				cout << "You escape!" << endl;
				is_fight = false;
			}
			else {
				cout << "You fail to escape." << endl;
			}
		}
		if (line == "2") {
			cout << "You... just hang around..." << endl;
		}
	}
}
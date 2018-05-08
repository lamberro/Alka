#include "stdafx.h"
#include "game.h"
#include "entity.h"
#include "player.h"
#include "location.h"
#include "forest.h"
#include <iostream>
#include <string>

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
		if (this->hero->get_xp() >= this->hero->get_max_xp()) {
			cout << endl;
			this->hero->level_up();
		}
		cout << endl;
		cout << "You are at your camp. What would you like to do?" << endl;
		cout << "[0] go to the forest." << endl;
		cout << "[1] sleep." << endl;
		cout << "[2] display player info." << endl;
		cout << "[3] Level up." << endl;
		cout << "[4] quit game." << endl;
		string line;
		getline(cin, line);

		cout << endl;
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
			hero->level_up();
		}
		if (line == "4") {
			game_running = false;
		}
	}
}

void Game::fight(Player * a, Entity * b) {
	cout << "You're in a fight!" << endl;
	bool is_fight = true;
	while (is_fight) {
		//verify that player is still alive
		//also used if player enters fight with no health
		if (a->get_hp() <= 0) {
			cout << "You have lost all health and have fainted." << endl;
			is_fight = false;
		}
		if (is_fight) {
			//display stats
			cout << endl;
			display_fight_info(a, b);

			//player action
			bool player_action = false;
			while (!player_action) {
				cout << endl;
				cout << "What would you like to do?" << endl;
				cout << "[0] Attack." << endl;
				cout << "[1] Attempt escape." << endl;
				cout << "[2] Just hang around, I guess." << endl;
				string line;
				getline(cin, line);

				cout << endl;
				if (line == "0") {
					player_action = true;
					cout << "You swing your fists" << endl;
					a->attack(a, b);
				}
				if (line == "1") {
					player_action = true;
					int escape = rand() % 100;
					if(a->escape(a, b)) {
						is_fight = false;
					}
				}
				if (line == "2") {
					player_action = true;
					cout << "You... just hang around..." << endl;
				}
			}

			if (is_fight) {
				cout << endl;
				//check that enemy is still alive
				if (b->get_hp() <= 0) {
					//enemy is dead
					cout << b->get_name() << " has fainted" << endl;
					int new_xp = b->drop_experience();
					a->set_xp(a->get_xp() + new_xp); //could be an increment xp function
					is_fight = false;
				}
				else {
					//enemy action
					b->choose_action(b, a, &is_fight);
				}
			}
		}
	}
}

void Game::display_fight_info(Entity * a, Entity * b) {
	cout << a->get_name() << ": " << "(HP: " << a->get_hp() << "/" << a->get_max_hp() << ")" << endl;
	cout << b->get_name() << ": " << "(HP: " << b->get_hp() << "/" << b->get_max_hp() << ")" << endl;
}
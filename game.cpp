#include "stdafx.h"
#include "game.h"
#include "entity.h"
#include "player.h"
#include "location.h"
#include "forest.h"
#include "coast.h"
#include "berry.h"
#include <iostream>
#include <string>
#include <fstream>

Game::Game() {
	this->hero = new Player;
	this->num_locations = 2;
	this->locations = new Location*[num_locations];
	//upon adding a new location, don't forget to update the copy constructor and assignment operator overload
	locations[0] = new Forest;
	locations[1] = new Coast;
	this->debug = false;
	this->day = 0;
	this->time = 8;
	this->inventory = new Inventory;
}

Game::Game(Player * p) {
	this->hero = p;
	this->num_locations = 2;
	this->locations = new Location*[num_locations];
	//upon adding a new location, don't forget to update the copy constructor and assignment operator overload
	locations[0] = new Forest;
	locations[1] = new Coast;
	this->debug = false;
	this->day = 0;
	this->time = 8;
	this->inventory = new Inventory;
}

Game::~Game() {
	delete hero;
	for (int i = 0; i < num_locations; i++) {
		delete locations[i];
	}
	delete[] locations;
	delete inventory;
}

Game::Game(const Game & copy) {
	this->hero = new Player;
	*hero = *copy.hero;
	this->num_locations = copy.num_locations;
	this->locations = new Location*[num_locations];
	locations[0] = new Forest;
	*locations[0] = *copy.locations[0];
	locations[1] = new Coast;
	*locations[1] = *copy.locations[1];
	this->debug = copy.debug;
	this->day = copy.day;
	this->time = copy.time;
	this->inventory = new Inventory;
	*inventory = *copy.inventory;
}

Game * Game::operator=(const Game & copy) {
	if(hero)
		delete hero;
	if (locations) {
		for (int i = 0; i < num_locations; i++) {
			delete locations[i];
		}
		delete[] locations;
	}
	if(inventory)
		delete inventory;

	this->hero = new Player;
	*hero = *copy.hero;
	this->num_locations = copy.num_locations;
	this->locations = new Location*[num_locations]; //changes with number of locations
	locations[0] = new Forest;
	*locations[0] = *copy.locations[0];
	locations[1] = new Coast;
	*locations[1] = *copy.locations[1];
	this->debug = copy.debug;
	this->day = copy.day;
	this->time = copy.time;
	this->inventory = new Inventory;
	*inventory = *copy.inventory;

	return this;
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

Inventory * Game::get_inventory() {
	return this->inventory;
}

int Game::get_time() {
	return this->time;
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

void Game::set_inventory(Inventory * inv) {
	this->inventory = inv;
}

void Game::set_time(int h) {
	this->time = h;
}

void Game::camp() {
	bool game_running = true;
	while (game_running == true) {
		if (this->hero->get_xp() >= this->hero->get_max_xp()) {
			this->hero->level_up();
			cout << endl;
		}
		cout << "You are at your camp. Today is day " << day << ". The time is ";
		if (time == 0)
			cout << "midnight." << endl;
		else {
			if (time < 12)
				cout << time << ":00am." << endl;
			else {
				if (time == 12)
					cout << "noon." << endl;
				else {
					cout << time-12 << ":00pm." << endl;
				}
			}
		}
		cout << "What would you like to do?" << endl;
		cout << "[0] go to the forest." << endl;
		cout << "[1] go to the coast." << endl;
		cout << "[2] sleep." << endl;
		cout << "[3] display player info." << endl;
		cout << "[4] view inventory." << endl;
		cout << "[5] save game." << endl;
		cout << "[6] load game." << endl;
		cout << "[7] quit game." << endl;
		if(debug)
			cout << "[8] DEBUG level up." << endl;
		string line;
		getline(cin, line);
		system("CLS");

		if (line == "0") {
			locations[0]->choose(hero, inventory);
			inc_time(1);
		}
		if (line == "1") {
			locations[1]->choose(hero, inventory);
			inc_time(1);
		}
		if (line == "2") {
			cout << "You sleep for eight hours." << endl;
			hero->heal(25);
			cout << "Your health is now: " << hero->get_hp() << "/" << hero->get_max_hp() << endl;
			inc_time(8);
		}
		if (line == "3") {
			cout << "Player info:" << endl;
			hero->display_stats();
		}
		if (line == "4") {
			cout << "Inventory:" << endl;
			view_inventory();
		}
		if (line == "5") {
			save_game();
		}
		if (line == "6") {
			load_game();
		}
		if (line == "7") {
			game_running = false; 
		}
		if (line == "8" && debug) {
			hero->level_up();
		}
		//DEBUG ACTIVATION
		if (line == "debug") {
			cout << "DEBUG MODE activated" << endl;
			debug = true;
		}
	}
}

//Player is entity a, enemy is entity b.
void Game::fight(Player * a, Entity * b) {
	cout << "You're in a fight!" << endl;
	cout << endl;
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
			display_fight_info(a, b);
			cout << endl;

			//player action
			bool player_action = false;
			while (!player_action) {
				cout << "What would you like to do?" << endl;
				cout << "[0] Attack." << endl;
				cout << "[1] Attempt escape." << endl;
				cout << "[2] Just hang around, I guess." << endl;
				string line;
				getline(cin, line);
				system("CLS");

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
			cout << endl;

			//poison for enemy b
			if (is_fight) {
				if (b->get_poisoned()) {
					cout << b->get_name() << " takes poison damage." << endl;
					b->poison_damage();
					cout << endl;
				}
			}

			if (is_fight) {
				//check that enemy is still alive
				if (b->get_hp() <= 0) {
					//enemy is dead
					cout << b->get_name() << " has fainted" << endl;
					int new_xp = b->drop_xp();
					a->gain_xp(new_xp);
					int new_gold = b->drop_gold();
					a->gain_gold(new_gold);
					//Item new_item = b->drop_item();
					//a->get_inventory()->add_to_inventory(new_item);
					is_fight = false;
					cout << endl;
				}
				else {
					//enemy action
					b->choose_action(b, a, &is_fight);
					cout << endl;
				}
			}
			//poison for player a
			if (is_fight) {
				if (a->get_poisoned()) {
					cout << a->get_name() << " takes poison damage." << endl;
					a->poison_damage();
					cout << endl;
				}
			}
		}
	}
	a->set_poisoned(false);
}

void Game::display_fight_info(Entity * a, Entity * b) {
	cout << a->get_name() << ": " << "(HP: " << a->get_hp() << "/" << a->get_max_hp() << ")" << endl;
	cout << b->get_name() << ": " << "(HP: " << b->get_hp() << "/" << b->get_max_hp() << ")" << endl;
}

void Game::save_game() {
	cout << "Saving data..." << endl;
	ofstream wf("savefile.txt", ofstream::out);
	
	wf << day << endl;
	wf << hero->get_name() << endl;
	wf << hero->get_gender() << endl;
	wf << hero->get_strength() << endl;
	wf << hero->get_toughness() << endl;
	wf << hero->get_speed() << endl;
	wf << hero->get_hp() << " ";
	wf << hero->get_max_hp() << endl;
	wf << hero->get_xp() << " ";
	wf << hero->get_max_xp() << endl;
	wf << hero->get_gold() << endl;
	wf << inventory->get_num_items() << " ";
	/*
	for (int i = 0; i < inventory->get_num_items(); i++) {
		wf << inventory->get_items()[i] << endl;
	}
	*/
	wf << endl << endl << "This file is saved in the format: " << endl;
	wf << "day#" << endl << "hero name" << endl << "gender" << endl << "strength" << endl << "toughness" << endl << "speed" << endl << "hp max_hp" << endl << "xp max_xp" << endl << "gold" << endl << "#items";
	wf.close();
	cout << "Data saved." << endl << endl;
}

void Game::load_game() {
	cout << "Loading data..." << endl;
	fstream rf("savefile.txt", istream::in);
	if (!rf.is_open()) {
		cout << "error loading file. No save file exists." << endl;
	}
	else {
		int temp_int = 0;
		bool temp_bool = false;
		string temp_s = "";
		rf >> day;
		rf >> temp_s;
		hero->set_name(temp_s);
		rf >> temp_bool;
		hero->set_gender(temp_bool);
		rf >> temp_int;
		hero->set_strength(temp_int);
		rf >> temp_int;
		hero->set_toughness(temp_int);
		rf >> temp_int;
		hero->set_speed(temp_int);
		rf >> temp_int;
		hero->set_hp(temp_int);
		rf >> temp_int;
		hero->set_max_hp(temp_int);
		rf >> temp_int;
		hero->set_xp(temp_int);
		rf >> temp_int;
		hero->set_max_xp(temp_int);
		rf >> temp_int;
		hero->set_gold(temp_int);
		/*
		rf >> temp_int;
		rf >> inventory->get_num_items() << " ";
		*/
		cout << "Load successful" << endl;
	}
	rf.close();
	cout << endl;
}

void Game::view_inventory() {
	bool keep_viewing = true;
	while (keep_viewing) {
		int num_items = inventory->get_items().size();
		for (int i = 0; i < num_items; i++) {
			cout << "Item #" << i + 1 << ": " << inventory->get_items()[i]->get_name() << " - " << inventory->get_items()[i]->get_description() << endl;
		}
		cout << "Which item would you like to use? Enter item #, or 'Q' to quit." << endl;
		if (!num_items)
			cout << "There are no items here" << endl;
		string input;
		getline(cin, input);
		system("CLS");
		if (input == "")
			input = "no input"; //protects from crashing
		if (input == "Q") {
			keep_viewing = false;
		}
		if (keep_viewing) {
			bool input_is_int = verify_pos_int(input);
			if (input_is_int) {
				int input_int = stoi(input);
				if (input_int <= num_items && input_int != 0) {
					Item * item_r = inventory->get_items()[input_int - 1];
					if (item_r->get_consumable()) {
						cout << "Consuming item..." << endl;
						item_r->consume(hero);
						inventory->remove_from_inventory(input_int-1);
					}
					else {
						cout << "You cannot consume this item... " << item_r->get_description() << endl;
					}
				}
				else {
					cout << "Input too large or is zero" << endl;
				}
			}
		}
	}
}

bool Game::verify_pos_int(string x) {
	int size = x.size();
	for (int i = 0; i < size; i++) {
		if (x[i] < '0' || x[i] > '9')
			return false;
	}
	return true;
}

void Game::player_creation(Player * p) {
	string input;
	//get name
	bool entering_name = true;
	while (entering_name) {
		cout << "Enter name: " << endl;
		getline(cin, input);
		system("CLS");

		cout << "Your name is " << input << "." << endl;
		bool affirm = Game::affirm();
		if (affirm) {
			p->set_name(input);
			entering_name = false;
		}
	}

	//get gender
	bool choosing_gender = true;
	while (choosing_gender) {
		cout << "[m]ale or [f]emale?" << endl;
		getline(cin, input);
		system("CLS");

		if (input == "m") {
			cout << "You're a man." << endl;
			bool affirm = Game::affirm();
			if (affirm) {
				p->set_gender(1);
				choosing_gender = false;
			}
		}
		if (input == "f") {
			cout << "You're a woman." << endl;
			bool affirm = Game::affirm();
			if (affirm) {
				p->set_gender(0);
				choosing_gender = false;
			}
		}
	}

	//get specialty
	bool chosen_specialty = false;
	while (!chosen_specialty) {
		cout << "Choose a specialty: " << endl;
		cout << "[0] fighting" << endl;
		cout << "[1] thieving" << endl;
		cout << "[2] masochism" << endl;
		getline(cin, input);
		system("CLS");
		if (input == "0") {
			cout << "Fighters' strengths: strength, toughness" << endl;
			cout << "Fighters' weaknesses: none" << endl;
			bool affirm = Game::affirm();
			if (affirm) {
				chosen_specialty = true;
				p->set_strength(12);
				p->set_toughness(12);
				p->set_speed(11);
				p->set_max_hp(100);
				p->set_hp(100);
				p->set_gold(0);
			}
		}
		if (input == "1") {
			cout << "Thieves' strengths: speed" << endl;
			cout << "Thieves' weaknesses: toughness" << endl;
			cout << "Thieves' bonus: more starting gold" << endl;
			bool affirm = Game::affirm();
			if (affirm) {
				chosen_specialty = true;
				p->set_strength(10);
				p->set_toughness(9);
				p->set_speed(14);
				p->set_max_hp(100);
				p->set_hp(100);
				p->set_gold(100);
			}
		}
		if (input == "2") {
			cout << "Masochists' strengths: toughness, HP" << endl;
			cout << "Masochists' weaknesses: none" << endl;
			bool affirm = Game::affirm();
			if (affirm) {
				chosen_specialty = true;
				p->set_strength(10);
				p->set_toughness(13);
				p->set_speed(10);
				p->set_max_hp(130);
				p->set_hp(130);
				p->set_gold(0);
			}
		}
	}

	//final affirmation
	p->display_stats();
	bool affirm = Game::affirm();
	if (!affirm) {
		Game::player_creation(p);
	}
}

bool Game::affirm() {
	bool inputting = true;
	while (inputting) {
		cout << "Is this okay? [y]/[n]." << endl;
		string input;
		getline(cin, input);
		system("CLS");
		if (input == "y") {
			return true;
		}
		if (input == "n") {
			return false;
		}
	}
}

void Game::inc_time(int x) {
	this->time += x;
	while (time >= 24) {
		time -= 24;
		this->day++;
	}
}
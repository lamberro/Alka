#include "stdafx.h"
#include "entity.h"
#include "player.h"
#include <string>
#include <iostream>

Player::Player() {
	name = "Hero";
	strength = 10;
	toughness = 10;
	hp = 100;
	max_hp = 100;
	speed = 10;
	xp = 0;
	max_xp = 100;
	gold = 0;
	inventory = new Inventory;
}

int Player::get_xp() {
	return this->xp;
}

int Player::get_max_xp() {
	return this->max_xp;
}

int Player::get_gold() {
	return this->gold;
}

Inventory * Player::get_inventory() {
	return this->inventory;
}

void Player::set_xp(int xp) {
	this->xp = xp;
}

void Player::set_max_xp(int max_xp) {
	this->max_xp = max_xp;
}

void Player::set_gold(int gold) {
	this->gold = gold;
}

void Player::set_inventory(Inventory * inv) {
	this->inventory = inv;
}

void Player::display_stats() {
	cout << "Name: " << this->name << endl;
	cout << "Strength: " << this->strength << endl;
	cout << "Toughness: " << this->toughness << endl;
	cout << "Speed: " << this->speed << endl;
	cout << "HP: " << this->hp << "/" << this->max_hp << endl;
	cout << "XP: " << this->xp << "/" << this->max_xp << endl;
	cout << "Gold: " << this->gold << endl;
}

void Player::view_inventory() {
	int num_items = this->inventory->get_items().size();
	for (int i = 0; i < num_items; i++) {
		cout << "Item #" << i + 1 << ": " << this->inventory->get_items()[i].get_name() << endl;
	}
}

void Player::level_up() {
	cout << "Level up!" << endl;
	xp = 0;
	max_xp += (max_xp * 0.5);
	strength += 10;
	toughness += 10;
	max_hp += 15;
	hp = max_hp;
	speed += 10;
}

void Player::gain_xp(int xp) {
	this->xp += xp;
}

void Player::gain_gold(int gold) {
	this->gold += gold;
}
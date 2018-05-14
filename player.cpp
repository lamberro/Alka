#include "stdafx.h"
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
}

Player::Player(const Player& copy) {
	name = copy.name;
	strength = copy.strength;
	toughness = copy.toughness;
	hp = copy.hp;
	max_hp = copy.max_hp;
	speed = copy.speed;
	xp = copy.xp;
	max_xp = copy.max_xp;
	gold = copy.gold;
}

Player * Player::operator=(const Player& copy) {
	name = copy.name;
	strength = copy.strength;
	toughness = copy.toughness;
	hp = copy.hp;
	max_hp = copy.max_hp;
	speed = copy.speed;
	xp = copy.xp;
	max_xp = copy.max_xp;
	gold = copy.gold;

	return this;
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

void Player::set_xp(int xp) {
	this->xp = xp;
}

void Player::set_max_xp(int max_xp) {
	this->max_xp = max_xp;
}

void Player::set_gold(int gold) {
	this->gold = gold;
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
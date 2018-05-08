#include "stdafx.h"
#include "entity.h"
#include "player.h"
#include <string>
#include <iostream>

using namespace std;

Player::Player() {
	name = "Hero";
	strength = 10;
	toughness = 10;
	hp = 100;
	max_hp = 100;
	speed = 10;
}

string Player::get_name(){
	return this->name;
}

int Player::get_strength() {
	return this->strength;
}

int Player::get_toughness() {
	return this->toughness;
}

int Player::get_hp() {
	return this->hp;
}

int Player::get_max_hp() {
	return this->max_hp;
}

int Player::get_speed() {
	return this->speed;
}

void Player::set_name(string name) {
	this->name = name;
}

void Player::set_strength(int strength) {
	this->strength = strength;
}

void Player::set_toughness(int toughness) {
	this->toughness = toughness;
}

void Player::set_hp(int hp) {
	this->hp = hp;
}

void Player::set_max_hp(int max_hp) {
	this->max_hp = max_hp;
}

void Player::set_speed(int speed) {
	this->speed = speed;
}

void Player::display_stats() {
	cout << "Name: " << this->name << endl;
	cout << "Strength: " << this->strength << endl;
	cout << "Toughness: " << this->toughness << endl;
	cout << "HP: " << this->hp << "/" << this->max_hp << endl;
	cout << "Speed: " << this->speed << endl;
}

void Player::heal(int x) {
	this->hp += x;
	if (hp > max_hp) {
		hp = max_hp;
	}
}

void Player::level_up() {
	strength += 10;
	toughness += 10;
	max_hp += 15;
	hp = max_hp;
	speed += 10;
}
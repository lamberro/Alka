#include "stdafx.h"

#include "entity.h"
#include <iostream>
#include <string>

using namespace std;

Entity::Entity() {
	name = "DEFAULT_ENTITY";
	strength = 0;
	toughness = 0;
	hp = 5;
	max_hp = 100;
	speed = 0;
}

string Entity::get_name() {
	return this->name;
}

int Entity::get_strength() {
	return this->strength;
}

int Entity::get_toughness() {
	return this->toughness;
}

int Entity::get_hp() {
	return this->hp;
}

int Entity::get_max_hp() {
	return this->max_hp;
}

int Entity::get_speed() {
	return this->speed;
}

void Entity::set_name(string name) {
	this->name = name;
}

void Entity::set_strength(int strength) {
	this->strength = strength;
}

void Entity::set_toughness(int toughness) {
	this->toughness = toughness;
}

void Entity::set_hp(int hp) {
	this->hp = hp;
}

void Entity::set_max_hp(int max_hp) {
	this->max_hp = max_hp;
}

void Entity::set_speed(int speed) {
	this->speed = speed;
}

void Entity::display_stats() {
	cout << "Name: " << this->name << endl;
	cout << "Strength: " << this->strength << endl;
	cout << "Toughness: " << this->toughness << endl;
	cout << "HP: " << this->hp << "/" << this->max_hp << endl;
	cout << "Speed: " << this->speed << endl;
}
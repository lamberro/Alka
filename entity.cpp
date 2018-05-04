#include "stdafx.h"

#include "entity.h"
#include <iostream>
#include <string>
#include <random>

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

int Entity::attack() {
	cout << "[DEBUG] Attack: " << this->strength * 2 << endl;
	return this->strength * 2;
}

void Entity::take_damage(int damage) {
	int x = damage - this->toughness;
	if (x < 0)
		x = 0;
	cout << "[DEBUG] Damage taken: " << x << endl;
	this->hp -= x;
}

//evade equation: chance = (evader's speed)/(attacker's speed * 5)
//equal speed gives 20% chance
bool Entity::evade(Entity * a, Entity * b) {
	int speed_a = a->get_speed();
	int speed_b = b->get_speed();
	float chance = (float)speed_a / (speed_b * 5);
	chance *= 100;
	int threshold = rand() % 100;
	if (chance > threshold) {
		cout << a->get_name() << " evaded the attack" << endl;
		return true;
	}
	return false;
}
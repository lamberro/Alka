#include "stdafx.h"

#include "entity.h"
#include <iostream>
#include <string>
#include <random>

Entity::Entity() {
	name = "DEFAULT_ENTITY";
	strength = 0;
	toughness = 0;
	hp = 5;
	max_hp = 100;
	speed = 0;
	poisoned = false;
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

bool Entity::get_poisoned() {
	return this->poisoned;
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

void Entity::set_poisoned(bool poisoned) {
	this->poisoned = poisoned;
}

void Entity::display_stats() {
	cout << "Name: " << this->name << endl;
	cout << "Strength: " << this->strength << endl;
	cout << "Toughness: " << this->toughness << endl;
	cout << "HP: " << this->hp << "/" << this->max_hp << endl;
	cout << "Speed: " << this->speed << endl;
}

void Entity::attack(Entity * a, Entity * b) {
	cout << a->get_name() << " lashes out." << endl; //I should make this more unique.
	bool enemy_evade = b->evade(b, a);
	if (enemy_evade == false) {
		int damage = a->get_strength() * 2;
		b->take_damage(damage);
	}
}

void Entity::take_damage(int damage) {
	int x = damage - this->toughness;
	if (x < 0)
		x = 0;
	this->hp -= x;
	cout << this->name << " takes " << x << " damage." << endl;
}

void Entity::heal(int x) {
	this->hp += x;
	if (hp > max_hp) {
		cout << this->name << "'s health maxed out at " << this->max_hp << endl;
		hp = max_hp;
	}
	else {
		cout << this->name << "'s health increased by " << x << endl;
	}
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

//currently the same as evade
bool Entity::escape(Entity * a, Entity * b) {
	cout << a->get_name() << " attempts an escape!" << endl;
	int speed_a = a->get_speed();
	int speed_b = b->get_speed();
	float chance = (float)speed_a / (speed_b * 5);
	chance *= 100;
	int threshold = rand() % 100;
	if (chance > threshold) {
		cout << a->get_name() << " escaped the fight." << endl;
		return true;
	}
	cout << a->get_name() << " failed to escape." << endl;
	return false;
}

void Entity::choose_action(Entity * a, Entity * b, bool * is_fight) { //unique to enemies, but this is the default
	a->attack(a, b);
}

//by default drop 5-10 xp
int Entity::drop_xp() {
	int xp = rand() % 5;
	xp += 5;
	cout << this->name << " dropped " << xp << " XP." << endl;
	return xp;
}

//by default drop 2-8 gold
int Entity::drop_gold() {
	int gold = rand() % 6;
	gold += 2;
	cout << this->name << " dropped " << gold << " gold." << endl;
	return gold;
}

void Entity::poison(Entity * a) {
	if (a->get_poisoned()) {
		cout << a->get_name() << " is already poisoned." << endl;
	}
	else {
		cout << a->get_name() << " is poisoned!" << endl;
		a->set_poisoned(true);
	}
}

//poison damage is currently 9% of max health + 1
void Entity::poison_damage() {
	int damage = this->max_hp * 0.09;
	damage++;
	this->hp -= damage;
}
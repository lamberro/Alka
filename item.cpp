#include "stdafx.h"
#include "item.h"
#include <iostream>

string Item::get_name() {
	return this->name;
}

string Item::get_description() {
	return this->description;
}

bool Item::get_consumable() {
	return this->consumable;
}

void Item::set_name(string name) {
	this->name = name;
}

void Item::set_description(string description) {
	this->description = description;
}

void Item::set_consumable(bool x) {
	this->consumable = x;
}

void Item::consume(Entity * a) {
	cout << "ERROR //ENTITY// CONSUME GENERIC ITEM OBJECT. (Probably forgot to add a consume function for something that can be consumable, or consumed something that shouldn't be consumable.)" << endl;
}

void Item::consume(Player * a) {
	cout << "ERROR //PLAYER// CONSUME GENERIC ITEM OBJECT. (Probably forgot to add a consume function for something that can be consumable, or consumed something that shouldn't be consumable.)" << endl;
}
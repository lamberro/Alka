#include "stdafx.h"
#include "item.h"
#include <iostream>

string Item::get_name() {
	return this->name;
}

bool Item::get_consumable() {
	return this->consumable;
}

void Item::set_name(string name) {
	this->name = name;
}

void Item::set_consumable(bool x) {
	this->consumable = x;
}

/*
void Item::consume(Player * a) {
	cout << "ERROR CONSUME GENERIC ITEM OBJECT. (Probably forgot to add a consume function for something that can be consumable, or consumed something that shouldn't be consumable.)" << endl;
}
*/
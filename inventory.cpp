#include "stdafx.h"
#include "inventory.h"

Inventory::Inventory() {
	max_items = 12;
	num_items = 0;
	items;
}

Inventory::~Inventory() {
	for (int i = 0; i < num_items; i++) {
		delete items[i];
	}
}

Inventory::Inventory(const Inventory & copy) {
	max_items = copy.max_items;
	num_items = copy.num_items;
	for (int i = 0; i < copy.num_items; i++) {
		Item a;
		Item * itemy = &a;
		items.push_back(itemy);
		*itemy = *copy.items[i];
	}
}

Inventory * Inventory::operator=(const Inventory & copy) {
	for (int i = 0; i < num_items; i++) {
		delete items[i];
	}
	max_items = copy.max_items;
	num_items = copy.num_items;
	for (int i = 0; i < copy.num_items; i++) {
		Item a;
		Item * itemy = &a;
		items.push_back(itemy);
		*itemy = *copy.items[i];
	}
	return this;
}

int Inventory::get_num_items() {
	return this->num_items;
}

vector<Item*> Inventory::get_items() {
	return this->items;
}

void Inventory::add_to_inventory(Item * item) {
	if (num_items >= max_items) {
		cout << "ERROR Too many items." << endl;
	}
	else {
		items.push_back(item);
		cout << item->get_name() << " added to bag" << endl;
		num_items++;
		cout << "Inventory now contains " << num_items << " items" << endl;
	}
}

void Inventory::remove_from_inventory(int x) {
	cout << items[x]->get_name() << " removed from bag" << endl;
	items.erase(items.begin() + x);
	num_items--;
	cout << "Inventory now contains " << num_items << " items" << endl;
}
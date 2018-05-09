#include "stdafx.h"
#include "inventory.h"

Inventory::Inventory() {
	max_items = 3;
	num_items = 0;
	items;
}

int Inventory::get_num_items() {
	return this->num_items;
}

vector<Item> Inventory::get_items() {
	return this->items;
}

void Inventory::add_to_inventory(Item item) {
	if (num_items >= max_items) {
		cout << "ERROR Too many items." << endl;
	}
	else {
		items.push_back(item);
		cout << item.get_name() << " added to bag" << endl;
		num_items++;
		cout << "Inventory now contains " << num_items << " items" << endl;
	}
}
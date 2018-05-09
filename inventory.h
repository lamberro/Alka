#ifndef INVENTORY_H
#define INVENTORY_H

#include "item.h"
#include <iostream>
#include <vector>

using namespace std;

//Inventory goals:
//3 inventory slots of items
//items can stack if multiple of the same item is collected
//functions for adding and removing from inventory should be in here
class Inventory {
private:
	int max_items;
	int num_items;
	vector<Item> items;
public:
	Inventory();

	int get_num_items();
	vector<Item> get_items();

	//I'm not allowing the program to set the slots for now. It just feels strange to allow that.

	void add_to_inventory(Item item);
};

#endif // !INVENTORY_H


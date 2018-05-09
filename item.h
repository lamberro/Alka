#ifndef ITEM_H
#define ITEM_H
//this will likely be broken up into consumables and other items, but idk
//the game doesn't even have an inventory yet, lol

#include "player.h"

class Item {
private:
	//
public:
	virtual void consume(Player * a) = 0;
};

#endif // !ITEM_H

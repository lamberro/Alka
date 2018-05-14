#ifndef LOCATION_H
#define LOCATION_H

#include "player.h"
#include "inventory.h"

using namespace std;

class Location {
private:
	//include events and chance of occurring
public:
	virtual void choose(Player * hero, Inventory * inv);

};


#endif
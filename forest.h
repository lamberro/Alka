#ifndef FOREST_H
#define FOREST_H

#include "location.h"
#include "entity.h"

using namespace std;

class Forest : public Location {
private:
	//
public:
	void choose(Player * hero, Inventory * inv);
	void pick_berries(Inventory * inv);
	void wander();
	void encounter_wolf(Player * hero);
	void encounter_rabbit(Player * hero);
	void encounter_spider(Player * hero);
};

#endif
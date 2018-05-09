#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"
#include "inventory.h"
#include <string>

using namespace std;

class Player : public Entity {
private:
	int xp;
	int max_xp;
	int gold;
	Inventory * inventory;
public:
	Player();

	int get_xp();
	int get_max_xp();
	int get_gold();
	Inventory * get_inventory();

	void set_xp(int xp);
	void set_max_xp(int max_xp);
	void set_gold(int gold);
	void set_inventory(Inventory * inv);

	void display_stats();
	void view_inventory();
	void level_up();
	void gain_xp(int xp);
	void gain_gold(int gold);
};

#endif
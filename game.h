#ifndef GAME_H
#define GAME_H

#include "entity.h"
#include "player.h"
#include "location.h"
#include "forest.h"
#include "inventory.h"

using namespace std;

class Game {
private:
	Player * hero;
	int num_locations;
	Location ** locations;
	bool debug;
	int day;
	Inventory * inventory;
public:
	Game();
	Game(Player * p);
	~Game();

	Player * get_player();
	int get_num_locations();
	Location ** get_locations();
	Inventory * get_inventory();

	void set_player(Player * new_hero);
	void set_num_locations(int num);
	void set_locations(Location ** new_locations);
	void set_inventory(Inventory * inv);

	void camp();
	static void fight(Player * a, Entity * b);
	static void display_fight_info(Entity * a, Entity * b);
	void save_game();
	void load_game();
	void view_inventory();
	static bool verify_pos_int(string x);
	static void player_creation(Player * p);
};

#endif
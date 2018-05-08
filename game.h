#ifndef GAME_H
#define GAME_H

#include "entity.h"
#include "player.h"
#include "location.h"
#include "forest.h"

using namespace std;

class Game {
private:
	Player * hero;
	int num_locations;
	Location ** locations;
public:
	Game();
	~Game();

	Player * get_player();
	int get_num_locations();
	Location ** get_locations();

	void set_player(Player * new_hero);
	void set_num_locations(int num);
	void set_locations(Location ** new_locations);

	void camp();
	static void fight(Player * a, Entity * b);
	static void display_fight_info(Entity * a, Entity * b);
};

#endif
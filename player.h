#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"
#include <string>

using namespace std;

class Player : public Entity {
private:
	int xp;
	int max_xp;
	int gold;
public:
	Player();
	Player(const Player& copy);
	Player * operator=(const Player& copy);
	//~Player();

	int get_xp();
	int get_max_xp();
	int get_gold();

	void set_xp(int xp);
	void set_max_xp(int max_xp);
	void set_gold(int gold);

	void display_stats();
	void level_up();
	void gain_xp(int xp);
	void gain_gold(int gold);
};

#endif
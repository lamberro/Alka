#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"
#include <string>

using namespace std;

class Player : public Entity {
private:
	int xp;
	int max_xp;
public:
	Player();

	string get_name();
	int get_strength();
	int get_toughness();
	int get_hp();
	int get_max_hp();
	int get_speed();
	int get_xp();
	int get_max_xp();

	void set_name(string name);
	void set_strength(int strength);
	void set_toughness(int toughness);
	void set_hp(int hp);
	void set_max_hp(int max_hp);
	void set_speed(int speed);
	void set_xp(int xp);
	void set_max_xp(int max_xp);

	void display_stats();
	void heal(int x);
	void level_up();
};

#endif
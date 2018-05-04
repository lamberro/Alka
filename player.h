#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"
#include <string>

using namespace std;

class Player : public Entity {
private:
	//
public:
	Player();

	string get_name();
	int get_strength();
	int get_toughness();
	int get_hp();
	int get_max_hp();
	int get_speed();

	void set_name(string name);
	void set_strength(int strength);
	void set_toughness(int toughness);
	void set_hp(int hp);
	void set_max_hp(int max_hp);
	void set_speed(int speed);

	void display_stats();
	void heal(int x);
};

#endif
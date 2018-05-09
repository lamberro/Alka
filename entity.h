#ifndef ENTITY_H
#define ENTITY_H

#include <string>

using namespace std;

class Entity {
protected:
	string name;
	int strength;
	int toughness;
	int hp;
	int max_hp;
	int speed;
	bool poisoned;
public:
	Entity();

	virtual string get_name();
	virtual int get_strength();
	virtual int get_toughness();
	virtual int get_hp();
	virtual int get_max_hp();
	virtual int get_speed();
	virtual bool get_poisoned();

	virtual void set_name(string name);
	virtual void set_strength(int strength);
	virtual void set_toughness(int toughness);
	virtual void set_hp(int hp);
	virtual void set_max_hp(int max_hp);
	virtual void set_speed(int speed);
	virtual void set_poisoned(bool poisoned);

	virtual void display_stats();
	virtual void attack(Entity * a, Entity * b);
	virtual void take_damage(int damage);
	virtual void heal(int x);
	virtual bool evade(Entity * a, Entity * b);
	virtual bool escape(Entity * a, Entity * b);
	virtual void choose_action(Entity * a, Entity * b, bool * is_fight); //used by enemies
	virtual int drop_xp(); //used by enemies
	virtual int drop_gold(); //used by enemies
	//virtual Item drop_item(); //used by enemies
	virtual void poison(Entity * a); //causes entity to be poisoned
	virtual void poison_damage(); //calculates and inflicts poison damage
};
#endif
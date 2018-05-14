#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "entity.h"
#include "player.h"

using namespace std;

class Item {
protected:
	string name;
	string description;
	bool consumable;
public:
	string get_name();
	string get_description();
	bool get_consumable();
	
	void set_name(string name);
	void set_description(string description);
	void set_consumable(bool x);
	
	virtual void consume(Entity * a); //the fact that this is Entity* and not Player* could easily be an issue in the future
	virtual void consume(Player * a); //the fact that this is Entity* and not Player* could easily be an issue in the future
};

#endif // !ITEM_H

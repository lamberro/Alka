#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

class Item {
protected:
	string name;
	bool consumable;
public:
	string get_name();
	bool get_consumable();
	
	void set_name(string name);
	void set_consumable(bool x);
	
	//virtual void consume(Player * a);
};

#endif // !ITEM_H

#ifndef BERRY_H
#define BERRY_H

#include "item.h"

class Berry : public Item {
private:
	bool rare;
	bool ultra_rare;
	bool super_ultra_rare;
public:
	Berry();

	void gen_rarity();

	virtual void consume(Entity * a);
	virtual void consume(Player * a);
};

#endif // !BERRY_H

#ifndef BERRY_H
#define BERRY_H

#include "item.h"

class Berry : public Item {
private:
	//
public:
	Berry();

	virtual void consume(Entity * a);
	virtual void consume(Player * a);
};

#endif // !BERRY_H

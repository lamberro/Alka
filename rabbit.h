#ifndef RABBIT_H
#define RABBIT_H

#include "entity.h"

using namespace std;

class Rabbit : public Entity {
private:
	//
public:
	Rabbit();

	void choose_action(Entity * a, Entity * b, bool * is_fight);
};

#endif // !RABBIT_H


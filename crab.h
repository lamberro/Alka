#ifndef CRAB_H
#define CRAB_H

#include "entity.h"

class Crab : public Entity {
private:
	//
public:
	Crab();

	void choose_action(Entity * a, Entity * b, bool * is_fight);
	void crustacean_stance();
};

#endif // !CRAB_H

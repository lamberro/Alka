#ifndef URCHIN_H
#define URCHIN_H

#include "entity.h"

using namespace std;

class Urchin : public Entity {
private:
	bool is_charging;
public:
	Urchin();

	virtual void choose_action(Entity * a, Entity * b, bool * is_fight);
	void start_charging();
	void charge_attack(Entity * a, Entity * b);
};

#endif // !URCHIN_H
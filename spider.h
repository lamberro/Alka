#ifndef SPIDER_H
#define SPIDER_H

#include "entity.h"
#include <string>

class Spider : public Entity {
private:
	//
public:
	Spider();

	void choose_action(Entity * a, Entity * b, bool * is_fight);
	int drop_experience();
};

#endif SPIDER_H // !SPIDER_H


#ifndef WOLF_H
#define WOLF_H

#include "entity.h"
#include <string>

class Wolf : public Entity {
private:
	//
public:
	Wolf();

	int drop_experience();
};

#endif
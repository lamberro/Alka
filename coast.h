#ifndef COAST_H
#define COAST_H

#include "location.h"
#include "player.h"

class Coast : public Location {
private:
	//
public:
	void choose(Player * hero);
	void wander();
	void encounter_crab(Player * hero);
};

#endif // !COAST_H


#include "stdafx.h"
#include "item.h"
#include "berry.h"
#include <iostream>

Berry::Berry() {
	name = "berry";
	description = "It is a handful of healthy berries.";
	consumable = true;
}

void Berry::consume(Entity * a) {
	cout << "Berry heals " << a->get_name() << " for 20." << endl;
	a->heal(20);
}

void Berry::consume(Player * a) {
	cout << "Berry heals " << a->get_name() << " for 20." << endl;
	a->heal(20);
}
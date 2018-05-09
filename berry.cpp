#include "stdafx.h"
#include "berry.h"

void Berry::consume(Player * a) {
	a->heal(5);
}
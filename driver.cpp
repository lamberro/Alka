// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

//idea: Make something like Corruption of Champions

#include "stdafx.h"

using namespace std;

#include <iostream>
#include <string>
#include <time.h>
#include <random>
#include "game.h"
#include "entity.h"
#include "player.h"
#include "wolf.h"
#include "location.h"
#include "forest.h"

int main()
{
	srand(time(NULL));
	Game G;
	G.camp();

    return 0;
}
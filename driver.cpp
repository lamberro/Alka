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

int main()
{
	srand(time(NULL));
	cout << "Welcome to Alka!" << endl;
	Player * p = new Player;
	Game::player_creation(p);
	Game G(p);
	G.camp();

    return 0;
}
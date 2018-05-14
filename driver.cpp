// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

//idea: Make something like Corruption of Champions

#include "stdafx.h"

using namespace std;

#include <iostream>
#include <string>
#include <time.h>
#include <random>
#include <windows.h>
#include <mmsystem.h>
#include "game.h"

int main()
{
	srand(time(NULL));
	
	cout << "Welcome to Alka!" << endl;

	bool inputting = true;
	bool music_on = false;
	while (inputting) {
		cout << "Would you like music? [y]/[n]" << endl;
		string input;
		getline(cin, input);
		if (input == "y") {
			music_on = true;
			inputting = false;
		}
		if (input == "n") {
			music_on = false;
			inputting = false;
		}
	}

	if(music_on)
		PlaySound(TEXT("Diddy.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

	Player * p = new Player;
	Game::player_creation(p);
	Game G(p);
	G.camp();

    return 0;
}
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

void play_music();
Game * startup();
void introduction();

int main()
{
	srand(time(NULL));
	
	cout << "Welcome to Alka!" << endl;

	play_music();

	Game G = *startup();

	G.camp();

    return 0;
}

void play_music() {
	bool inputting = true;
	bool music_on = false;
	while (inputting) {
		cout << "Would you like music? [y]/[n]" << endl;
		string input;
		getline(cin, input);
		system("CLS");

		if (input == "y") {
			music_on = true;
			inputting = false;
		}
		if (input == "n") {
			music_on = false;
			inputting = false;
		}
	}

	if (music_on)
		PlaySound(TEXT("Diddy.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

Game * startup() {
	bool inputting = true;
	string input;
	while (inputting) {
		cout << "[n]ew game or [l]oad game?" << endl;
		getline(cin, input);
		system("CLS");
		if (input == "l") {
			Player * p = new Player;
			Game G(p);
			G.load_game();
			Game * gp = new Game;
			*gp = G;
			return gp;
		}
		if (input == "n") {
			Player * p = new Player;
			Game::player_creation(p);
			Game G(p);
			Game * gp = new Game;
			*gp = G;
			introduction();
			return gp;
		}
	}
}

void introduction() {
	cout << "You had a crazy dream last night where you were falling from space and you crash landed on some crazy world..." << endl;
	cout << "But as it turns out..." << endl;
	cout << "When you awoke... YOU WERE ON THAT NEW WORLD AFTER ALL!!" << endl;
	cout << endl;
	cout << "You left quite the crater in the wake of your fall, as well." << endl;
	cout << "Regardless, you spend a day exploring your immediate surroundings and putting together a ramshackle campsite." << endl;
	cout << "I'd say it turned out pretty well." << endl;
	cout << endl;
}
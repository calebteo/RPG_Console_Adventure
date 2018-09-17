// Game is a treasure hunting game. The character is moving around a 2D array. There is a treasure to find, when character position is equal to treasure position, you win and games end. 
// There is also Creatures (Wolves and Ogres) which will engage a battle mode. 
// Game is over when health or energy is zero. Health decrease from battle, energy decreases from moving. 
// Class Terrain has a 2D array. The file input is "Introduction.txt". There is a Creature class and Hero, Wolf and Ogre inherit class Creature. 


#include "Terrain.h"
#include "Hero.h"
#include <string>
#include <iostream>
#include <fstream>
#include "time.h"
#include <Windows.h>
#include <conio.h>

using namespace std; 

void main() {

	Hero hunter;
	Terrain base;
	Terrain printBase(' ');
	int r = 27; 
	int c = 0; 

	int r2 = 47;

	ifstream file;

	file.open("Introduction.txt");

	string line;

	while (getline(file, line)) {
		cout << line << '\n';
	}


	int ci, cj;
	//base.generateTerrain(inputFile);
	base.generateCreatures();

	/*
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << i << "   " << j << "        " << base.base[i][j].space << endl;

		}
	}
	
	int i, j;
	cout << "Enter: ";
	cin >> i >> j;
	cout << base.base[i][j].w->health;
	*/

	base.generateChest(ci, cj);
	//cout << ci << " , " << cj << endl;

	
	char move;
	cout << "Enter your name: ";
	cin >> hunter.name;
	cout << endl;
	
	base.transfermapping(printBase, hunter.getpi(), hunter.getpj());
	printBase.base[hunter.getpi()][hunter.getpj()].space = 'Y';

	cout << "*_*_* BEGINNING ADVENTURE *_*_*" << endl; 
	cout << "Move with 'WASD'" << endl << endl;

	


	while (!hunter.checkIfWin(ci, cj)) {
		//base.printSurroundings(hunter.getpi(), hunter.getpj());
		//base.printHere(r, c);
		printBase.printHere(r, c); 
		hunter.printstats();
		
		int picreature, pjcreature;
		if (hunter.checkCreatures(base, picreature, pjcreature)) {
			hunter.BattleMode(base, picreature, pjcreature, r2, c); 
			//base.transfermapping(printBase, hunter.getpi(), hunter.getpj());
			if (hunter.health <= 0) {
				cout << "You have died. You failed the mission and the treasure is forever lost..." << endl; 
				cout << " ----|----GAME OVER ----|----" << endl; 
				cout << "Enter any key to close program: "; 
				_getch();
				break;
				
			}
			//base.printSurroundings(hunter.getpi(), hunter.getpj());
			printBase.printHere(r, c);
		}
		
		
		move = _getch(); 
		hunter.move(move, base, printBase);
		if (hunter.energy == 0) {
			cout << "You are out of energy." << endl;
			cout << "You have died.You failed the mission and the treasure is forever lost..." << endl;
			break;
		}
		

	}
	if (hunter.checkIfWin(ci, cj)) {
		base.flushNumRowAtrc(10, r2, 0);
		cout << "CONGRATULATIONS, YOU WIN" << endl; 
		cout << "Enter any key to close program: ";
		_getch();
	}
	
}